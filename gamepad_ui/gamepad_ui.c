/**
 * @file gamepad_ui.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "gamepad_ui.h"
#include <SDL2/SDL.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct {
    SDL_Scancode sc;
    const char * name;
    lv_obj_t * obj;
    bool shown;
} overlay_entry_t;

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void overlay_bind_objects(lv_obj_t * root);
static void overlay_set(SDL_Scancode sc, bool pressed);

/**********************
 *  STATIC VARIABLES
 **********************/

/* Map scancodes -> object names from your screen_main_create() */
static overlay_entry_t s_overlay[] = {
    { SDL_SCANCODE_ESCAPE,    "btn_MENU",   NULL, false },

    { SDL_SCANCODE_E,         "btn_L",     NULL, false },
    { SDL_SCANCODE_TAB,       "btn_L2",     NULL, false },

    { SDL_SCANCODE_T,         "btn_R",     NULL, false },
    { SDL_SCANCODE_BACKSPACE, "btn_R2",     NULL, false },

    { SDL_SCANCODE_RIGHT,     "btn_RIGHT",  NULL, false },
    { SDL_SCANCODE_UP,        "btn_UP",     NULL, false },
    { SDL_SCANCODE_LEFT,      "btn_LEFT",   NULL, false },
    { SDL_SCANCODE_DOWN,      "btn_DOWN",   NULL, false },

    { SDL_SCANCODE_RCTRL,     "btn_SELECT", NULL, false },
    { SDL_SCANCODE_RETURN,    "btn_START",  NULL, false },

    { SDL_SCANCODE_LALT,      "btn_Y",      NULL, false },
    { SDL_SCANCODE_LSHIFT,    "btn_X",      NULL, false },
    { SDL_SCANCODE_SPACE,     "btn_A",      NULL, false },
    { SDL_SCANCODE_LCTRL,     "btn_B",      NULL, false },
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void gamepad_ui_init(const char * asset_path)
{
    gamepad_ui_init_gen(asset_path);

    /* Add your own custom code here if needed */
#if !defined(LV_EDITOR_PREVIEW)
    lv_obj_t * screen_main = screen_main_create();
    lv_screen_load(screen_main);
    overlay_bind_objects(screen_main);
#endif
}

void gamepad_ui_overlay_refresh(const uint8_t * keys)
{
    const size_t n = sizeof(s_overlay) / sizeof(s_overlay[0]);

    for (size_t i = 0; i < n; i++) {
        overlay_entry_t * e = &s_overlay[i];
        if (e->obj == NULL) continue;
        const bool down = keys[e->sc] != 0;
        overlay_set(e->sc, down);
    }
}

void on_btn_clicked_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);

    switch (code)
    {
        case LV_EVENT_PRESSED:
            lv_obj_set_style_opa(obj, 255, LV_PART_MAIN);
            break;
        case LV_EVENT_RELEASED:
            lv_obj_set_style_opa(obj, 0, LV_PART_MAIN);
        default:
            break;
    }
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void overlay_bind_objects(lv_obj_t * root)
{
    const size_t n = sizeof(s_overlay) / sizeof(s_overlay[0]);
    for (size_t i = 0; i < n; i++) {
        s_overlay[i].obj = lv_obj_get_child_by_name(root, s_overlay[i].name);
        if (s_overlay[i].obj == NULL) {
            LV_LOG_WARN("overlay '%s' not found", s_overlay[i].name);
        }
    }
}

static void overlay_set(SDL_Scancode sc, bool pressed)
{
    const size_t n = sizeof(s_overlay) / sizeof(s_overlay[0]);
    for (size_t i = 0; i < n; i++) {
        overlay_entry_t *e = &s_overlay[i];
        if (e->sc != sc || e->obj == NULL) continue;

        if (pressed && !e->shown) {
            lv_obj_set_style_opa(e->obj, 255, LV_PART_MAIN);
            e->shown = true;
        } else if (!pressed && e->shown) {
            lv_obj_set_style_opa(e->obj, 0, LV_PART_MAIN);
            e->shown = false;
        }
        break;
    }
}