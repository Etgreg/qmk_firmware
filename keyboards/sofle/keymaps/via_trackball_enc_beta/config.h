/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#define MASTER_RIGHT

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define CUSTOM_FONT

#define CUSTOM_LAYER_READ //if you remove this it causes issues - needs better guarding


#define TAPPING_FORCE_HOLD
#ifdef TAPPING_TERM
    #undef TAPPING_TERM
    #define TAPPING_TERM 200
#endif
#define ENCODER_DIRECTION_FLIP

/* #undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4 */

#define PIMORONI_TRACKBALL_INVERT_Y
#define PIMORONI_TRACKBALL_INVERT_X
#define PIMORONI_TRACKBALL_INTERVAL_MS 5
#define PIMORONI_TRACKBALL_SCALE 3

#define RGBLIGHT_SLEEP
//
#define RGBLIGHT_LAYERS

#if defined(KEYBOARD_sofle_rev1)
// Add RGB underglow and top facing lighting
#    define RGB_DI_PIN D3
#    define RGBLED_NUM 72
#    define RGBLED_SPLIT \
        { 36, 36 }
#    ifdef RGB_MATRIX_ENABLE
#        define DRIVER_LED_TOTAL RGBLED_NUM
#        define RGB_MATRIX_SPLIT RGBLED_SPLIT
#        define SPLIT_TRANSPORT_MIRROR
#    else
//#		define RGBLIGHT_EFFECT_STATIC_GRADIENT
#		define RGBLIGHT_EFFECT_RAINBOW_SWIRL
/* #		define RGBLIGHT_EFFECT_RAINBOW_MOOD */
#    endif
#endif






