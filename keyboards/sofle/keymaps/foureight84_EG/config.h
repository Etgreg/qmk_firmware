#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MASTER_RIGHT

/* clear default encoder def */
#undef TAP_CODE_DELAY

/* encoder support */
#define TAP_CODE_DELAY 100

#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

#ifndef NO_DEBUG
#define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#define NO_PRINT
#endif // !NO_PRINT

//Add RGB underglow
#define RGB_DI_PIN D3
#define RGBLED_NUM 14
#define RGBLED_SPLIT {7,7}
#define RGBLIGHT_ANIMATIONS
