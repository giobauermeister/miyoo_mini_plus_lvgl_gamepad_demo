#ifndef LV_CONF_H
#define LV_CONF_H

/* ---- Core display/timing ---- */
#define LV_COLOR_DEPTH           16
#define LV_DEF_REFR_PERIOD       33
#define LV_TICK_CUSTOM           0

/* ---- Logging (optional) ---- */
#define LV_USE_LOG               1
#define LV_LOG_LEVEL             LV_LOG_LEVEL_INFO
#define LV_LOG_PRINTF            1

/** 1: Enable system monitor component */
#define LV_USE_SYSMON   1
#if LV_USE_SYSMON
    /** Get the idle percentage. E.g. uint32_t my_get_idle(void); */
    #define LV_SYSMON_GET_IDLE lv_os_get_idle_percent

    /** 1: Show CPU usage and FPS count.
     *  - Requires `LV_USE_SYSMON = 1` */
    #define LV_USE_PERF_MONITOR 1
    #if LV_USE_PERF_MONITOR
        #define LV_USE_PERF_MONITOR_POS LV_ALIGN_BOTTOM_RIGHT

        /** 0: Displays performance data on the screen; 1: Prints performance data using log. */
        #define LV_USE_PERF_MONITOR_LOG_MODE 0
    #endif

    /** 1: Show used memory and memory fragmentation.
     *     - Requires `LV_USE_STDLIB_MALLOC = LV_STDLIB_BUILTIN`
     *     - Requires `LV_USE_SYSMON = 1`*/
    #define LV_USE_MEM_MONITOR 0
    #if LV_USE_MEM_MONITOR
        #define LV_USE_MEM_MONITOR_POS LV_ALIGN_BOTTOM_LEFT
    #endif
#endif /*LV_USE_SYSMON*/

/* ---- Memory: use glibc malloc on desktop/mini ---- */
#define LV_USE_STDLIB_MALLOC     LV_STDLIB_CLIB
/* If you switch to LV_STDLIB_BUILTIN, also set:
   #define LV_MEM_SIZE (1024 * 1024)
*/

#define LV_USE_OBJ_NAME         1

/* ---- SDL backend ---- */
#define LV_USE_SDL               1
#define LV_SDL_RENDER_MODE       LV_DISPLAY_RENDER_MODE_DIRECT
#define LV_SDL_BUF_COUNT         1
#define LV_SDL_ACCELERATED       1
#define LV_SDL_FULLSCREEN        0
#define LV_SDL_DIRECT_EXIT       1
#define LV_SDL_MOUSEWHEEL_MODE   LV_SDL_MOUSEWHEEL_MODE_ENCODER

/* ---- Demos ---- */
#define LV_USE_DEMO_WIDGETS      0

/* ================================
   IMPORTANT: make SDL include overrideable
   Desktop builds typically use <SDL2/SDL.h>
   Miyoo cross build will override to <SDL.h> via CMake.
   ================================ */
#ifndef LV_SDL_INCLUDE_PATH
#  define LV_SDL_INCLUDE_PATH  <SDL2/SDL.h>
#endif

/* ---- Fonts ---- */
/* Make sure at least one Montserrat font is actually compiled in: */
#define LV_FONT_MONTSERRAT_14 1
/* Pick it as the default */
#define LV_FONT_DEFAULT &lv_font_montserrat_14

#endif /* LV_CONF_H */
