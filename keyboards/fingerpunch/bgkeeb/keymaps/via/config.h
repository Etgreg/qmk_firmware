
#pragma once

#define POINTING_DEVICE_ROTATION_90
#define PIMORONI_TRACKBALL_INTERVAL_MS 5
#define PIMORONI_TRACKBALL_SCALE 5

#define DYNAMIC_KEYMAP_LAYER_COUNT 5

/* Reduce tapdance required taps from 5 to 2 */
#define TAPPING_TOGGLE 3

#define RGBLIGHT_LAYERS

#define MASTER_LEFT


#undef RGBLED_SPLIT 
#define RGBLED_SPLIT { 21, 21 }
#undef RGBLED_NUM 
#define RGBLED_NUM 42