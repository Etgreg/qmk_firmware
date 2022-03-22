/* Copyright 2020 imchipwood
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
#include QMK_KEYBOARD_H

enum custom_keycodes {
    QMKfindteams = SAFE_RANGE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
            BASE LAYER
    /-----------------------------------------------------`
    |             |    7    |    8    |    9    |  Bkspc  |
    |             |---------|---------|---------|---------|
    |             |    4    |    5    |    6    |   Esc   |
    |             |---------|---------|---------|---------|
    |             |    1    |    2    |    3    |   Tab   |
    |-------------|---------|---------|---------|---------|
    | Left mouse  |  TT(1)  |    0    |    .    |  Enter  |
    \-----------------------------------------------------'
    */
    [0] = LAYOUT(
                    KC_7,      	RCS(KC_M),    RCS(KC_O),             KC_BSPC,
                    RCS(KC_A),  RCS(KC_K),    RCS(KC_E),        RCS(KC_H),
                    KC_1,      	KC_2,    		KC_3,             KC_TAB,
        TT(1),    	KC_BSPC,     KC_DEL,    RCTL(KC_SPC),   QMKfindteams
    ),
    /*
            SUB LAYER
    /-----------------------------------------------------`
    |             |         |         |         |  Reset  |
    |             |---------|---------|---------|---------|
    |             |         |         |         |    +    |==++
    |             |---------|---------|---------|---------|
    |             |         |         |         |    -    |
    |-------------|---------|---------|---------|---------|
    |    LOCK     |         |         |         |    =    |
    \-----------------------------------------------------'
    */
    [1] = LAYOUT(
                    _______,     KC_ESC,     KC_TAB,      RESET,
                    KC_C,     KC_E,     KC_R,      KC_O,
                    KC_H,     KC_M,     _______,      KC_KP_MINUS,
        TO(2),    KC_BSPC,     KC_DEL,     _______,      KC_EQL
    ),
	
	    [2] = LAYOUT(
                    _______,     KC_ESC,     KC_TAB,      RESET,
                    KC_F9,     KC_F10,    KC_F11,     KC_F12,
                    KC_F5,     KC_F6,    KC_F7,     KC_F8,
        TO(0),    KC_F1,     KC_F2,    KC_F3,     KC_F4
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QMKfindteams:
        if (record->event.pressed) {
            // when keycode" QMKfindteams is pressed
            SEND_STRING(SS_LGUI("22"));
        } else {
            // when keycode QMKfindteams is released
        }
        break;
    }
    return true;
};

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    // debug_enable = true;
    // debug_matrix = true;
    // debug_keyboard = true;
    // debug_mouse = true;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    /*  Custom encoder control - handles CW/CCW turning of encoder
     *  Default behavior:
     *    left encoder:
     *      main layer:
     *         CW: move mouse right
     *        CCW: move mouse left
     *      other layers:
     *         CW: = (equals/plus - increase slider in Adobe products)
     *        CCW: - (minus/underscore - decrease slider in adobe products)
     *    right encoder:
     *      main layer:
     *         CW: colume up
     *        CCW: volume down
     *      other layers:
     *         CW: right arrow
     *        CCW: left arrow
     */
    if (index == 0) {
        switch (get_highest_layer(layer_state)) {
            case 0:
                // main layer - move mouse right (CW) and left (CCW)
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
				
			case 2:
                // main layer - move mouse right (CW) and left (CCW)
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;

            default:
                // other layers - =/+ (quals/plus) (CW) and -/_ (minus/underscore) (CCW)
                if (clockwise) {
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                }
                break;
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case 0:
                // main layer - volume up (CW) and down (CCW)
                if (clockwise) {
                    tap_code16(C(KC_Y));
                } else {
					tap_code16(C(KC_Z));
                }
                break;

            default:
                // other layers - right (CW) and left (CCW)
                if (clockwise) {
                    tap_code(KC_WFWD);
                } else {
                    tap_code(KC_WBAK);
                }
                break;
        }
    }
	return true;
}
