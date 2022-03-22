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
	BALL_HUI = SAFE_RANGE, //cycles hue
  BALL_WHT,              //cycles white
  BALL_DEC,              //decreased color
  BALL_SCR,              //scrolls
  BALL_NCL,              //left click
  BALL_RCL,              //right click
  BALL_MCL,              //middle click
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_MINS, KC_PGUP, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_VOLD, KC_PGDN, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, RALT(KC_LBRC), RALT(KC_RBRC), KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_WBAK, KC_WFWD, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, KC_GRV, KC_LALT, KC_LGUI, KC_LALT, KC_LCTL, KC_SPC, MO(1), MO(2), KC_ENT, KC_RALT, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL),

[_LAYER1] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_MPLY, KC_RCBR, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_MUTE, KC_PLUS, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F12, KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, LCA(KC_GRV), RALT(KC_BSLS), KC_H, KC_J, KC_K, KC_L, KC_COLN, KC_DQUO, KC_LSFT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_SPC, KC_ENT, KC_N, KC_M, KC_LT, KC_GT, KC_QUES, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, LALT(KC_GRV), KC_TRNS, KC_SPC, KC_DEL, MO(3), KC_ENT, KC_BSPC, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

[_LAYER2] = LAYOUT(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LCBR, KC_HOME, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_UNDS, KC_END, KC_PGUP, KC_AMPR, KC_UP, KC_LPRN, KC_RPRN, KC_F12, KC_TAB, KC_1, KC_2, KC_3, KC_4, KC_5, KC_DEL, KC_BSPC, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL, KC_DQUO, KC_LSFT, KC_6, KC_7, KC_8, KC_9, KC_0, KC_SPC, KC_ENT, KC_N, KC_M, KC_LT, KC_GT, KC_QUES, KC_RSFT, KC_LCTL, KC_LGUI, KC_LALT, LALT(KC_GRV), KC_DEL, KC_SPC, MO(3), KC_TRNS, KC_ENT, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END),

[_LAYER3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS,  BALL_DEC , BALL_WHT, BALL_HUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, KC_TRNS, KC_TRNS, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BL_TOGG, BL_BRTG, BL_INC, BL_DEC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS) 

};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

uint8_t white = 255;
uint8_t red = 0;
uint8_t green = 0;
uint8_t blue = 0;

bool set_scrolling = false;
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (layer_state_is(_LAYER2)) {
        set_scrolling = true;
    } else {
        set_scrolling = false;
    }
	
	if (set_scrolling) {
        mouse_report.h = mouse_report.x/2;
        mouse_report.v = -mouse_report.y/2;
        mouse_report.x = mouse_report.y = 0; 
    }
    return mouse_report;
}

void ball_increase_hue(void){
      if(red!=255&&green!=255&&blue!=255){
        red =255;
      }
      if (red==255&&green<255&&blue==0){
       green += 15;
      } else if(green==255&&blue==0&&red>0){
        red-=15;
      } else if(red==0&&blue<255&&green==255){
        blue+=15;
      } else if(blue==255&&green>0&&red==0){
        green -= 15;
      } else if(green == 0&&blue==255&&red<255){
        red +=15;
      } else if(green ==0&&blue>0&&red==255){
        blue -=15;
      }
      pimoroni_trackball_set_rgbw(red,green,blue,white);
}

void decrease_color(void){
  if (green>0){
    green-=15;
  }
  if (red>0){
    red-=15;
  }
  if (blue>0){
    blue-=15;
  }
  pimoroni_trackball_set_rgbw(red,green,blue,white);
}

void cycle_white(void){
  if (white<255){
    white +=15;
  } else{
    white=0;
  }
  pimoroni_trackball_set_rgbw(red,green,blue,white);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record){
  switch (keycode){
  case  BALL_HUI:
    if(record->event.pressed){
      ball_increase_hue();
    }
    break;

  case BALL_WHT:
    if(record-> event.pressed){
      cycle_white();
    }
    break;

  case BALL_DEC:
   if(record-> event.pressed){
      decrease_color();
    }
    break;

  case BALL_SCR:
   if(record->event.pressed){
     set_scrolling = true;
   } else{
     set_scrolling = false;
   }
   break;

  }
  return true;
}