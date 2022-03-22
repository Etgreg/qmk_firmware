/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |      | Knob 2: Page Dn/Up |
        | Press: Mute       | Home | Press: Play/Pause  |
        | Hold: Layer 2     | Up   | RGB Mode           |
        | Left              | Down | Right              |
     */
    [0] = LAYOUT(
        KC_MUTE, KC_HOME, KC_MPLY,
        MO(1)  , KC_UP  , KC_F5,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),
    /*
        | RESET          | N/A  | Media Stop |
        | Held: Layer 2  | Home | RGB toggle   |
        | Media Previous | End  | Media Next |
     */
    [1] = LAYOUT(
        RESET  , BL_STEP, KC_STOP,
        _______, KC_HOME, MO(2),
        KC_MPRV, KC_END , KC_DEL
    ),
	
	[2] = LAYOUT(
        RGB_VAI, RGB_TOG,RGB_VAD, 
        _______, RGB_HUI, _______,
        RGB_SAD, RGB_HUD, RGB_SAI
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
		if(IS_LAYER_ON(1)) { // on Raise layer control volume
			if (clockwise){
			  rgblight_increase();
			} else{
			  rgblight_decrease();
			}        
		  } else { // on other layers emulate mouse scrollwheel
			if (clockwise){
			  tap_code(KC_VOLU);
			} else{
			  tap_code(KC_VOLD);
			}
		  }
    }
    else if (index == _MIDDLE) {
        if(IS_LAYER_ON(1)) { // on Raise layer control volume
			if (clockwise){
			   rgblight_increase_val();
			} else{
			   rgblight_decrease_val();
			}        
		  } else { // on other layers emulate mouse scrollwheel
			if (clockwise) {
				tap_code(KC_DOWN);
			} else {
				tap_code(KC_UP);
			}
		  }
    }
    else if (index == _RIGHT) {
        if(IS_LAYER_ON(2)) { // on Raise layer control volume
			if (clockwise){
			   rgblight_increase_hue();
			} else{
			   rgblight_decrease_hue();
			}
		} else if(IS_LAYER_ON(1)) { // on Raise layer control volume
			if (clockwise){
			   rgblight_increase_sat();
			} else{
			   rgblight_decrease_sat();
			} 			
		  } else { // on other layers emulate mouse scrollwheel
			if (clockwise) {
				tap_code(KC_PGDN);
			} else {
				tap_code(KC_PGUP);
			}
		  } 

    }
}
