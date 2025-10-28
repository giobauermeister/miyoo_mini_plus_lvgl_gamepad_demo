#include "lvgl.h"
#include "src/drivers/sdl/lv_sdl_window.h"

#include <SDL2/SDL.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "gamepad_ui/gamepad_ui.h"

/* --- Miyoo Mini+ (Onion SDL) keycodes ---
 * D-Pad:     SDLK_UP/DOWN/LEFT/RIGHT
 * A:         SDLK_SPACE
 * B:         SDLK_LCTRL
 * X:         SDLK_LSHIFT
 * Y:         SDLK_LALT
 * L1:        SDLK_e
 * R1:        SDLK_t
 * L2:        SDLK_TAB
 * R2:        SDLK_BACKSPACE
 * Select:    SDLK_RCTRL
 * Start:     SDLK_RETURN
 * Menu:      SDLK_ESCAPE
 */

typedef struct {
    SDL_Scancode sc;
    uint32_t lvk;
    bool down;
    uint64_t next_ms;
} hold_key_t;

typedef struct {
    uint32_t key[16];
    uint8_t rd, wr, cnt;
    bool send_release;
    uint32_t last_key;
} key_fifo_t;

static const uint32_t REPEAT_DELAY_MS    = 400;  /* initial delay before repeating */
static const uint32_t REPEAT_INTERVAL_MS = 55;   /* repeat rate while held */
static volatile bool g_quit = false;
static key_fifo_t g_fifo;

/* FIFO helper functions */
static inline void fifo_clear(key_fifo_t *q){
    q->rd=q->wr=q->cnt=0;
    q->send_release=false;
    q->last_key=0;
}

static inline void fifo_push(key_fifo_t *q, uint32_t k)
{
    if(q->cnt >= (int)(sizeof(q->key)/sizeof(q->key[0]))) return;
    q->key[q->wr] = k;
    q->wr = (q->wr + 1) & (16-1);
    q->cnt++;
}

static inline bool fifo_pop(key_fifo_t *q, uint32_t *k)
{
    if(!q->cnt) return false;
    *k = q->key[q->rd];
    q->rd = (q->rd + 1) & (16-1);
    q->cnt--;
    return true;
}

static void fifo_remove_key(key_fifo_t *q, uint32_t lvk)
{
    uint32_t tmp[16];
    int n = 0;

    while(q->cnt) {
        uint32_t k;
        fifo_pop(q, &k);
        if(k != lvk && n < (int)(sizeof(tmp)/sizeof(tmp[0]))) tmp[n++] = k;
    }
    q->rd = q->wr = q->cnt = 0;
    for(int i=0;i<n;i++) {
        fifo_push(q, tmp[i]);
    }

    if(q->send_release && q->last_key == lvk) {
        q->send_release = false;
    }
}

/* LVGL keypad read_cb */
static void keypad_read_cb(lv_indev_t * indev, lv_indev_data_t * data)
{
    (void)indev;

    if (g_fifo.send_release) {
        data->key   = g_fifo.last_key;
        data->state = LV_INDEV_STATE_RELEASED;
        g_fifo.send_release = false;
        data->continue_reading = false;
        return;
    }

    uint32_t k;
    if (fifo_pop(&g_fifo, &k)) {
        g_fifo.last_key = k;
        g_fifo.send_release = true;
        data->key = k;
        data->state = LV_INDEV_STATE_PRESSED;
    } else {
        data->state = LV_INDEV_STATE_RELEASED;
    }
    data->continue_reading = false;
}

static uint64_t now_ms(void)
{
    struct timespec ts; clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000ULL + ts.tv_nsec/1000000ULL;
}

/* --- MAPPING TABLE --- */
static hold_key_t g_keys[] = {
    /* D-Pad */
    { SDL_SCANCODE_UP,        LV_KEY_UP,        false, 0 },
    { SDL_SCANCODE_DOWN,      LV_KEY_DOWN,      false, 0 },
    { SDL_SCANCODE_LEFT,      LV_KEY_LEFT,      false, 0 },
    { SDL_SCANCODE_RIGHT,     LV_KEY_RIGHT,     false, 0 },

    /* Face buttons */
    { SDL_SCANCODE_SPACE,     LV_KEY_ENTER,     false, 0 }, // A
    { SDL_SCANCODE_LCTRL,     LV_KEY_ESC,       false, 0 }, // B
    { SDL_SCANCODE_LSHIFT,    0,                false, 0 }, // X
    { SDL_SCANCODE_LALT,      0,                false, 0 }, // Y

    /* Shoulders */
    { SDL_SCANCODE_E,         LV_KEY_PREV,      false, 0 }, // L1
    { SDL_SCANCODE_TAB,       LV_KEY_NEXT,      false, 0 }, // L2
    { SDL_SCANCODE_T,         LV_KEY_NEXT,      false, 0 }, // R1
    { SDL_SCANCODE_BACKSPACE, LV_KEY_BACKSPACE, false, 0 }, // R2

    { SDL_SCANCODE_RETURN,    LV_KEY_ENTER,     false, 0 }, // Start
    { SDL_SCANCODE_RCTRL,     0,                false, 0 }, // Select
};

static void poll_keyboard_state(const Uint8 * keys)
{
    const uint64_t t = now_ms();

    for (size_t i = 0; i < sizeof(g_keys) / sizeof(g_keys[0]); i++) {
        hold_key_t *hk = &g_keys[i];

        if (hk->lvk == 0) {
            continue;
        }

        bool is_down = keys[hk->sc] != 0;

        if (is_down && !hk->down) {
            fifo_push(&g_fifo, hk->lvk);
            hk->down = true;
            hk->next_ms = t + REPEAT_DELAY_MS;
        }
        else if (is_down && hk->down) {
            if (t >= hk->next_ms) {
                fifo_push(&g_fifo, hk->lvk);
                hk->next_ms += REPEAT_INTERVAL_MS;
            }
        }
        else if (!is_down && hk->down) {
            hk->down = false;
            fifo_remove_key(&g_fifo, hk->lvk);
        }
    }
}

int main(void)
{
    lv_init();
    fifo_clear(&g_fifo);

    lv_group_t *grp = lv_group_create();
    lv_group_set_default(grp);
    lv_group_set_wrap(grp, true);

    lv_display_t * disp = lv_sdl_window_create(640, 480);
    if (!disp) { 
        fprintf(stderr,"lv_sdl_window_create failed\n");
        return 1;
    }
    lv_display_set_default(disp);

    lv_indev_t *indev = lv_indev_create();
    lv_indev_set_type(indev, LV_INDEV_TYPE_KEYPAD);
    lv_indev_set_read_cb(indev, keypad_read_cb);
    lv_indev_set_group(indev, grp);
    lv_indev_set_display(indev, disp);

    LV_LOG_USER("STARTING LVGL");

    gamepad_ui_init(NULL);

    uint64_t last = now_ms();

    while(!g_quit) {
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                g_quit = true;
                break;
            }
        }

        SDL_PumpEvents();
        const Uint8 * keys = SDL_GetKeyboardState(NULL);

        /* Select+Menu key combo for exiting the app */
        if (keys[SDL_SCANCODE_RCTRL] && 
            keys[SDL_SCANCODE_ESCAPE]) {
            g_quit = true;
        }

        poll_keyboard_state(keys);

        gamepad_ui_overlay_refresh(keys);

        uint64_t t = now_ms();
        lv_tick_inc((uint32_t)(t - last));
        last = t;

        uint32_t sleep_ms = lv_timer_handler();
        if(sleep_ms == LV_NO_TIMER_READY) {
            sleep_ms = LV_DEF_REFR_PERIOD;
        }
        usleep(sleep_ms * 1000);
    }

    return 0;
}
