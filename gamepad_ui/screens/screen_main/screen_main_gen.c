/**
 * @file screen_main_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "screen_main_gen.h"
#include "gamepad_ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * screen_main_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    lv_obj_t * lv_image_0 = lv_image_create(NULL);
    lv_obj_set_name_static(lv_image_0, "screen_main_#");
    lv_image_set_src(lv_image_0, img_background);

    lv_obj_t * btn_MENU = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_MENU, "btn_MENU");
    lv_image_set_src(btn_MENU, img_lvgl_glow);
    lv_obj_set_x(btn_MENU, 277);
    lv_obj_set_y(btn_MENU, 127);
    lv_obj_set_style_opa(btn_MENU, 0, 0);
    lv_obj_set_flag(btn_MENU, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_MENU, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_MENU, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_L2 = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_L2, "btn_L2");
    lv_image_set_src(btn_L2, img_L2_glow);
    lv_obj_set_x(btn_L2, 105);
    lv_obj_set_y(btn_L2, 7);
    lv_obj_set_style_opa(btn_L2, 0, 0);
    lv_obj_set_flag(btn_L2, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_L2, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_L2, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_L = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_L, "btn_L");
    lv_image_set_src(btn_L, img_L1_glow);
    lv_obj_set_x(btn_L, 32);
    lv_obj_set_y(btn_L, 28);
    lv_obj_set_style_opa(btn_L, 0, 0);
    lv_obj_set_flag(btn_L, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_L, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_L, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_R2 = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_R2, "btn_R2");
    lv_image_set_src(btn_R2, img_R2_glow);
    lv_obj_set_x(btn_R2, 423);
    lv_obj_set_y(btn_R2, 7);
    lv_obj_set_style_opa(btn_R2, 0, 0);
    lv_obj_set_flag(btn_R2, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_R2, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_R2, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_R = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_R, "btn_R");
    lv_image_set_src(btn_R, img_R1_glow);
    lv_obj_set_x(btn_R, 509);
    lv_obj_set_y(btn_R, 28);
    lv_obj_set_style_opa(btn_R, 0, 0);
    lv_obj_set_flag(btn_R, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_R, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_R, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_RIGHT = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_RIGHT, "btn_RIGHT");
    lv_image_set_src(btn_RIGHT, img_arrow_glow);
    lv_obj_set_x(btn_RIGHT, 174);
    lv_obj_set_y(btn_RIGHT, 253);
    lv_obj_set_style_opa(btn_RIGHT, 0, 0);
    lv_obj_set_flag(btn_RIGHT, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_RIGHT, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_RIGHT, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_UP = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_UP, "btn_UP");
    lv_image_set_src(btn_UP, img_arrow_glow);
    lv_obj_set_x(btn_UP, 106);
    lv_obj_set_y(btn_UP, 193);
    lv_image_set_rotation(btn_UP, 1500);
    lv_obj_set_style_opa(btn_UP, 0, 0);
    lv_obj_set_flag(btn_UP, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_UP, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_UP, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_LEFT = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_LEFT, "btn_LEFT");
    lv_image_set_src(btn_LEFT, img_arrow_glow);
    lv_obj_set_x(btn_LEFT, 44);
    lv_obj_set_y(btn_LEFT, 251);
    lv_image_set_rotation(btn_LEFT, 1800);
    lv_obj_set_style_opa(btn_LEFT, 0, 0);
    lv_obj_set_flag(btn_LEFT, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_LEFT, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_LEFT, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_DOWN = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_DOWN, "btn_DOWN");
    lv_image_set_src(btn_DOWN, img_arrow_glow);
    lv_obj_set_x(btn_DOWN, 106);
    lv_obj_set_y(btn_DOWN, 312);
    lv_image_set_rotation(btn_DOWN, 2100);
    lv_obj_set_style_opa(btn_DOWN, 0, 0);
    lv_obj_set_flag(btn_DOWN, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_DOWN, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_DOWN, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_SELECT = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_SELECT, "btn_SELECT");
    lv_image_set_src(btn_SELECT, img_select_start_glow);
    lv_obj_set_x(btn_SELECT, 244);
    lv_obj_set_y(btn_SELECT, 376);
    lv_obj_set_style_opa(btn_SELECT, 0, 0);
    lv_obj_set_flag(btn_SELECT, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_SELECT, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_SELECT, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_START = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_START, "btn_START");
    lv_image_set_src(btn_START, img_select_start_glow);
    lv_obj_set_x(btn_START, 309);
    lv_obj_set_y(btn_START, 376);
    lv_obj_set_style_opa(btn_START, 0, 0);
    lv_obj_set_flag(btn_START, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_START, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_START, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_Y = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_Y, "btn_Y");
    lv_image_set_src(btn_Y, img_Y_glow);
    lv_obj_set_x(btn_Y, 371);
    lv_obj_set_y(btn_Y, 246);
    lv_obj_set_style_opa(btn_Y, 0, 0);
    lv_obj_set_flag(btn_Y, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_Y, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_Y, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_X = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_X, "btn_X");
    lv_image_set_src(btn_X, img_X_glow);
    lv_obj_set_x(btn_X, 437);
    lv_obj_set_y(btn_X, 180);
    lv_obj_set_style_opa(btn_X, 0, 0);
    lv_obj_set_flag(btn_X, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_X, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_X, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_A = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_A, "btn_A");
    lv_image_set_src(btn_A, img_A_glow);
    lv_obj_set_x(btn_A, 502);
    lv_obj_set_y(btn_A, 245);
    lv_obj_set_style_opa(btn_A, 0, 0);
    lv_obj_set_flag(btn_A, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_A, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_A, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);
    
    lv_obj_t * btn_B = lv_image_create(lv_image_0);
    lv_obj_set_name(btn_B, "btn_B");
    lv_image_set_src(btn_B, img_B_glow);
    lv_obj_set_x(btn_B, 437);
    lv_obj_set_y(btn_B, 311);
    lv_obj_set_style_opa(btn_B, 0, 0);
    lv_obj_set_flag(btn_B, LV_OBJ_FLAG_CLICKABLE, true);
    lv_obj_add_event_cb(btn_B, on_btn_clicked_cb, LV_EVENT_PRESSED, NULL);
    lv_obj_add_event_cb(btn_B, on_btn_clicked_cb, LV_EVENT_RELEASED, NULL);

    LV_TRACE_OBJ_CREATE("finished");

    return lv_image_0;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

