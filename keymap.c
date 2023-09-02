/*
Copyright 2020 Dimitris Mantzouranis

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

enum layer_names {
  L_BASE = 0,
  L_DEV,
  L_UNIC,
  L_NAV,
};

enum custom_keycodes {
  KC_AE = SAFE_RANGE,
  KC_UE,
  KC_OE,
};

enum unicode_names {
  U_AE,
  U_ae,
  U_UE,
  U_ue,
  U_OE,
  U_oe,
  U_THUMBUP,
  U_THUMBDWN,
  U_WINK,
  U_LAUGH,
  U_SWEAT,
  U_SMILE,
  U_KISS,
  U_HEART,
};

const uint32_t PROGMEM unicode_map[] = {
  [U_AE] = 0xC4,          // Ä
  [U_ae] = 0xE4,          // ä
  [U_UE] = 0xDC,          // Ü
  [U_ue] = 0xFC,          // ü
  [U_OE] = 0xD6,          // Ö
  [U_oe] = 0xF6,          // ö
  [U_THUMBUP] = 0x1F44D,  // 👍
  [U_THUMBDWN] = 0x1F44E, // 👎
  [U_WINK] = 0x1F609,     // 😉
  [U_LAUGH] = 0x1F602,    // 😂
  [U_SWEAT] = 0x1F605,    // 😅
  [U_SMILE] = 0x1F60A,    // 😊
  [U_KISS] = 0x1F618,     // 😘
  [U_HEART] = 0x2764FE0F, // ❤️
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
        +--------------------------------------------------------------------------+----------------+
        | ESC |  | F1 | F2 | F3 | F4 | | F5 | F6 | F7 | F8 | | F9| F10| F11| F12|  | |PSCR|????|PAUS|
        +--------------------------------------------------------------------------+------|----|----|
        |  ~  |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = | BACKSP | |INS |SCRL|PGUP|
        +--------------------------------------------------------------------------+------|----|----|
        |  TAB  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] |   \  | |DEL |END |PGDN|
        +--------------------------------------------------------------------------+------|----|----|
        | CAPSLCK  |  A |  S |  D |  F |  G |  H |  J |  K |  L | ; | ' |  RETURN  |                |
        +--------------------------------------------------------------------------+      |----|    |
        | LSHIFT     |  Z |  X |  C |  V |  B |  N |  M | , | . |  / |   RSHIFT    |      | UP |    |
        +--------------------------------------------------------------------------+------|----|----|
        |LCTRL| LGUI| LALT |            SPACE            | RALT| RGUI | FN | RCTRL | |LFT |DWN |RGT |
        +--------------------------------------------------------------------------+----------------+
*/

    [L_BASE] = {
      {   KC_ESC,      KC_F1,        KC_F2,        KC_F3,        KC_F4,         KC_F5,    KC_F6,   KC_F7,        KC_F8,        KC_F9,        KC_F10,          KC_F11,    KC_F12,    KC_NO,     KC_PSCR,   TG(2),     RGB_MODE_FORWARD},
      {   KC_GRV,      KC_1,         KC_2,         KC_3,         KC_4,          KC_5,    KC_6,     KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,   KC_EQL,    KC_BSPC,   KC_INS,    KC_HOME,   KC_PGUP},
      {   KC_TAB,      KC_Q,         KC_W,         KC_E,         KC_R,          KC_T,    KC_Z,     KC_U,         KC_I,         KC_O,         KC_P,            KC_LBRC,   KC_RBRC,   KC_BSLS,   KC_DEL,    KC_END,    KC_PGDN},
      {   KC_ESC,      LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),  KC_G,    KC_H,     RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,   KC_NO,     KC_ENT,    KC_NO,     KC_NO,     KC_NO},
      {   KC_LSFT,     KC_NO,        KC_Y,         KC_X,         KC_C,          KC_V,    KC_B,     KC_N,         KC_M,         KC_COMM,      KC_DOT,          KC_SLSH,   KC_NO,     KC_RSFT,   KC_NO,     KC_UP,     KC_NO},
      {   KC_LCTL,     KC_LGUI,      MO(L_DEV),    KC_NO,        KC_NO,         KC_NO,   LT(L_NAV,KC_SPC),KC_NO, KC_NO,        KC_NO,        MO(L_DEV),       KC_RGUI,   MO(L_UNIC),KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT}
    },
    [L_DEV] = {
      {   _______,      _______,  _______,  _______,  LALT(KC_F4),_______,  _______,  _______,  _______,  _______,   _______,     _______,   _______,  KC_NO,    _______,  _______,  _______ },
      {   _______,      _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,   _______,     _______,   _______,  _______,  _______,  _______,  _______ },
      {   LALT(KC_TAB), _______,  KC_AT,    KC_PERC,  KC_AMPR,    _______,  KC_ASTR,  KC_TILD,  _______,  _______,   _______,     _______,   _______,  _______,  _______,  _______,  _______ },
      {   _______,      KC_EXLM,  KC_UNDS,  KC_DLR,   KC_MINUS,   KC_PLUS,  KC_PIPE,  KC_EQUAL, _______,  _______,   _______,     _______,   KC_NO,    _______,  KC_NO,    KC_NO,    KC_NO },
      {   LALT(KC_LSFT),_______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,   _______,     _______,   KC_NO,    _______,  KC_NO,    _______,  KC_NO },
      {   _______,      _______,  _______,  KC_NO,    KC_NO,      KC_NO,    KC_SPC,   KC_NO,    KC_NO,    KC_NO,     _______,     _______,   _______,  _______,  _______,  _______,  _______ }
    },
    [L_UNIC] = {
      {   RESET,    _______,  _______,    _______,  _______,  _______,  _______,    _______,      _______,    _______,   _______,     _______,   _______,  KC_NO,    _______,  _______,  RGB_TOG },
      {   _______,  _______,  _______,    _______,  _______,  _______,  _______,    _______,      _______,    _______,   _______,     _______,   _______,  _______,  _______,  RGB_M_P,  RGB_HUI },
      {   _______,  _______,  X(U_WINK),  _______,  _______,  _______,  _______,    KC_UE,        _______,    KC_OE,     _______,     _______,   _______,  _______,  _______,  RGB_SAI,  RGB_SPI },
      {   _______,  KC_AE,    X(U_SMILE), _______,  _______,  _______,  X(U_HEART), _______,      X(U_KISS),  X(U_LAUGH),_______,     _______,   KC_NO,    _______,  KC_NO,    KC_NO,    KC_NO },
      {   _______,  _______,  _______,    _______,  _______,  _______,  _______,    X(U_THUMBDWN),X(U_SWEAT), _______,   _______,     _______,   KC_NO,    _______,  KC_NO,    KC_VOLU,  KC_NO },
      {   _______,  _______,  _______,    KC_NO,    KC_NO,    KC_NO,    _______,    KC_NO,        KC_NO,      KC_NO,     _______,     _______,   _______,  _______,  _______,  _______,  _______ }
    },
    [L_NAV] = {
      {   _______,  _______,  _______,    _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______,  KC_NO,    _______,  _______,  _______ },
      {   _______,  KC_NO,    KC_NO,      KC_NO,    KC_NO,    _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______ },
      {   _______,  KC_NO,    KC_NO,      KC_NO,    KC_NO,    _______,  _______,   KC_HOME,  _______,  KC_END,  _______,  _______,   _______,  _______,  _______,  _______,  _______ },
      {   _______,  _______,  _______,    _______,  _______,  KC_PGUP,  KC_LEFT,   KC_DOWN,  KC_UP,    KC_RIGHT, KC_PGDN,  _______,   KC_NO,    _______,  KC_NO,    KC_NO,    KC_NO },
      {   _______,  KC_NO,    KC_NO,      KC_NO,    KC_DEL,   KC_BSPC,  _______,   _______,  _______,  _______,  _______,  _______,   KC_NO,    _______,  KC_NO,    _______,  KC_NO },
      {   _______,  _______,  _______,    KC_NO,    KC_NO,    KC_NO,    _______,   KC_NO,    KC_NO,      KC_NO,  _______,  _______,   _______,  _______,  _______,  _______,  _______ }
    },
};

void dip_switch_update_user(uint8_t index, bool active){
  switch(index){
    case 0:
      if(active){ /*BT mode*/ } else { /*Cable mode*/ }
      break;
    case 1:
      if(active){ /*Win/Android mode*/ } else{ /*Mac/iOS mode*/ }
      break;
  }
}
void keyboard_post_init_user(void) {
  rgblight_disable();
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) return true;
  const bool shift = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;
  switch (keycode) {
    case KC_AE:
      register_unicode(unicode_map[shift ? U_AE : U_ae]);
      return false;
    case KC_UE:
      register_unicode(unicode_map[shift ? U_UE : U_ue]);
      return false;
    case KC_OE:
      register_unicode(unicode_map[shift ? U_OE : U_oe]);
      return false;
  }
  return true;
}
