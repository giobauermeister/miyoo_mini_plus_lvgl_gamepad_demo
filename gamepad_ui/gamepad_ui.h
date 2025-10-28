/**
 * @file gamepad_ui.h
 */

#ifndef GAMEPAD_UI_H
#define GAMEPAD_UI_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#include "gamepad_ui_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the component library
 */
void gamepad_ui_init(const char * asset_path);
void gamepad_ui_overlay_refresh(const uint8_t * keys);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*GAMEPAD_UI_H*/