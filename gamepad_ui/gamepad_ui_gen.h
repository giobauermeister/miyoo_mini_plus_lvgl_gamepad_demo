/**
 * @file gamepad_ui_gen.h
 */

#ifndef GAMEPAD_UI_GEN_H
#define GAMEPAD_UI_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

/*----------------
 * Images
 *----------------*/

extern const void * img_background;
extern const void * img_lvgl_glow;
extern const void * img_arrow_glow;
extern const void * img_select_start_glow;
extern const void * img_A_glow;
extern const void * img_B_glow;
extern const void * img_X_glow;
extern const void * img_Y_glow;
extern const void * img_R1_glow;
extern const void * img_R2_glow;
extern const void * img_L1_glow;
extern const void * img_L2_glow;

/*----------------
 * Subjects
 *----------------*/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

void on_btn_clicked_cb(lv_event_t * e);

/**
 * Initialize the component library
 */

void gamepad_ui_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widget and components of this library*/
#include "screens/screen_main/screen_main_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*GAMEPAD_UI_GEN_H*/