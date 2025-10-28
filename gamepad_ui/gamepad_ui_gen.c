/**
 * @file gamepad_ui_gen.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "gamepad_ui_gen.h"

#if LV_USE_XML
#endif /* LV_USE_XML */

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/

/*----------------
 * Images
 *----------------*/

const void * img_background;
extern const void * img_background_data;
const void * img_lvgl_glow;
extern const void * img_lvgl_glow_data;
const void * img_arrow_glow;
extern const void * img_arrow_glow_data;
const void * img_select_start_glow;
extern const void * img_select_start_glow_data;
const void * img_A_glow;
extern const void * img_A_glow_data;
const void * img_B_glow;
extern const void * img_B_glow_data;
const void * img_X_glow;
extern const void * img_X_glow_data;
const void * img_Y_glow;
extern const void * img_Y_glow_data;
const void * img_R1_glow;
extern const void * img_R1_glow_data;
const void * img_R2_glow;
extern const void * img_R2_glow_data;
const void * img_L1_glow;
extern const void * img_L1_glow_data;
const void * img_L2_glow;
extern const void * img_L2_glow_data;

/*----------------
 * Subjects
 *----------------*/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void gamepad_ui_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Fonts
     *----------------*/


    /*----------------
     * Images
     *----------------*/
    img_background = &img_background_data;
    img_lvgl_glow = &img_lvgl_glow_data;
    img_arrow_glow = &img_arrow_glow_data;
    img_select_start_glow = &img_select_start_glow_data;
    img_A_glow = &img_A_glow_data;
    img_B_glow = &img_B_glow_data;
    img_X_glow = &img_X_glow_data;
    img_Y_glow = &img_Y_glow_data;
    img_R1_glow = &img_R1_glow_data;
    img_R2_glow = &img_R2_glow_data;
    img_L1_glow = &img_L1_glow_data;
    img_L2_glow = &img_L2_glow_data;

    /*----------------
     * Subjects
     *----------------*/
    /*----------------
     * Translations
     *----------------*/

#if LV_USE_XML
    /* Register widgets */

    /* Register fonts */

    /* Register subjects */

    /* Register callbacks */
    lv_xml_register_event_cb(NULL, "on_btn_clicked_cb", on_btn_clicked_cb);
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)
    /* Register images */
    lv_xml_register_image(NULL, "img_background", img_background);
    lv_xml_register_image(NULL, "img_lvgl_glow", img_lvgl_glow);
    lv_xml_register_image(NULL, "img_arrow_glow", img_arrow_glow);
    lv_xml_register_image(NULL, "img_select_start_glow", img_select_start_glow);
    lv_xml_register_image(NULL, "img_A_glow", img_A_glow);
    lv_xml_register_image(NULL, "img_B_glow", img_B_glow);
    lv_xml_register_image(NULL, "img_X_glow", img_X_glow);
    lv_xml_register_image(NULL, "img_Y_glow", img_Y_glow);
    lv_xml_register_image(NULL, "img_R1_glow", img_R1_glow);
    lv_xml_register_image(NULL, "img_R2_glow", img_R2_glow);
    lv_xml_register_image(NULL, "img_L1_glow", img_L1_glow);
    lv_xml_register_image(NULL, "img_L2_glow", img_L2_glow);
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/
    /* If XML is enabled it's assumed that the permanent screens are created
     * manaully from XML using lv_xml_create() */
#endif
}

/* Callbacks */
#if defined(LV_EDITOR_PREVIEW)
void __attribute__((weak)) on_btn_clicked_cb(lv_event_t * e)
{
    LV_UNUSED(e);
    LV_LOG("on_btn_clicked_cb was called\n");
}
#endif

/**********************
 *   STATIC FUNCTIONS
 **********************/