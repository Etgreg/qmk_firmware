/* Copyright 2018
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

enum layer_names {
  _BASE,
  _LOWER,
  _FUNCTION,
  _RAISE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_ortho_5x12( 
    KC_ESC,   KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,    KC_7,     KC_8,      KC_9,     KC_0,     KC_BSPC,
    KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,    KC_U,     KC_I,      KC_O,     KC_P,     KC_BSLS,  
    KC_GRV,   KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,    KC_J,     KC_K,      KC_L,     KC_SCLN,  KC_QUOT, 
    KC_LSFT,  KC_Z,     KC_X,     KC_C,    KC_V,     KC_B,     KC_N,    KC_M,     KC_COMM,   KC_DOT,   KC_SLSH,  KC_SFTENT,  
    KC_LCTL,  KC_LGUI,  KC_LALT,  KC_LCTL,   LOWER,    KC_SPC,   KC_ENT,  RAISE,    KC_RALT, KC_LBRC, KC_RBRC,  KC_RGHT  
  ),

    [_LOWER] = LAYOUT_ortho_5x12( 
    KC_ESC,	  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11, 
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC, KC_CIRC, KC_AMPR,   KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_F12,  
    KC_DEL,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_UNDS,   KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE, 
    _______,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,  KC_F12,  _______,   _______,  KC_HOME,  KC_END,   _______, 
    _______,  _______,  _______,  _______,  _______,  _______, _______, FUNCT,   KC_MNXT,  KC_MINS,  KC_EQL,  KC_MPLY  
  ),

    [_FUNCTION] = LAYOUT_ortho_5x12(
    KC_NO,    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    KC_CAPS,  RESET,    RGB_TOG,   RGB_MOD,  KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_UP,    KC_NO,    KC_PSCR,  KC_NO, 
    _______,  KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_NO,    KC_NO,
    KC_NO,    KC_NO,    KC_NO,     KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,
    _______,  _______,  _______,   _______,  _______,  _______, _______, _______,  KC_MPRV,  KC_PGUP,  KC_PGDN,  KC_MNXT
  ),

    [_RAISE] = LAYOUT_ortho_5x12( 
    KC_GRV,  KC_1,    KC_2,      KC_3,     KC_4,     KC_5,    KC_6,    KC_7,     KC_8,     KC_LCBR,  KC_RCBR,  KC_BSPC, 
    KC_GRV,  KC_1,    KC_2,      KC_3,     KC_4,     KC_5,    KC_6,    KC_7,     KC_UP,     KC_9,     KC_0,     KC_DEL,  
    KC_DEL,  KC_F1,   KC_F2,     KC_F3,    KC_F4,    KC_F5,   KC_F6,   KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_DEL,   KC_BSLS, 
    _______, KC_F7,   KC_F8,     KC_F9,    KC_F10,   KC_F11,  KC_F12,  KC_NUHS,  KC_NUBS,  KC_PGUP,  KC_PGDN,  _______, 
    RGB_TOG, RGB_MOD, BL_INC,    BL_DEC,   FUNCT,  _______, _______, _______,  KC_MNXT,  KC_VOLU,  KC_VOLD,  KC_MPLY  
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {

}