#include QMK_KEYBOARD_H


#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_VOLU, KC_PGUP, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_VOLD, KC_PGDN, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, RALT(KC_LBRC), RALT(KC_RBRC), KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_WBAK, KC_WFWD, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, KC_GRV, KC_LALT, KC_LGUI, KC_LALT, KC_LCTL, KC_SPC, MO(1), MO(2), KC_ENT, KC_RALT, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL),

[_LAYER1] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_MPLY, KC_RCBR, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_MUTE, KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12, KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, LCA(KC_GRV), RALT(KC_BSLS), KC_H, KC_J, KC_K, KC_L, KC_COLN, KC_DQUO, KC_LSFT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_SPC, KC_ENT, KC_N, KC_M, KC_LT, KC_GT, KC_QUES, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, LALT(KC_GRV), KC_TRNS, KC_SPC, KC_DEL, MO(3), KC_ENT, KC_BSPC, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

[_LAYER2] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LCBR, KC_HOME, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_UNDS, KC_END, KC_PGUP, KC_AMPR, KC_UP, KC_LPRN, KC_RPRN, KC_F12, KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_DEL, KC_BSPC, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_DQUO, KC_LSFT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_SPC, KC_ENT, KC_N, KC_M, KC_LT, KC_GT, KC_QUES, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, LALT(KC_GRV), KC_DEL, KC_SPC, MO(3), KC_TRNS, KC_ENT, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

[_LAYER3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, KC_TRNS, KC_TRNS, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_TOGG, BL_BRTG, BL_INC, BL_DEC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS) 

};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LAYER0:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_LAYER0);
      }
      return false;
      break;
    case LAYER1:
      if (record->event.pressed) {
        layer_on(_LAYER1);
        update_tri_layer(_LAYER1, _LAYER2, _LAYER3);
      } else {
        layer_off(_LAYER1);
        update_tri_layer(_LAYER1, _LAYER2, _LAYER3);
      }
      return false;
      break;
    case LAYER2:
      if (record->event.pressed) {
        layer_on(_LAYER1);
        update_tri_layer(_LAYER1, _LAYER2, _LAYER3);
      } else {
        layer_off(_LAYER1);
        update_tri_layer(_LAYER1, _LAYER2, _LAYER3);
      }
      return false;
      break;
    case LAYER3:
      if (record->event.pressed) {
        layer_on(_LAYER3);
      } else {
        layer_off(_LAYER3);
      }
      return false;
      break;
  }
  return true;
}
