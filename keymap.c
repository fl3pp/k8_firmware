#include QMK_KEYBOARD_H

static bool is_mac = true;
/* Windows Mods to Mac:
   Alt -> Option
   Control -> Control
   Windows Key -> Command */

enum layer_names {
  L_BASE = 0,
  L_DEV,
};

enum custom_keycodes {
  KC_OSTOG = SAFE_RANGE,
  KC_DIAERESIS,
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
      {   KC_ESC,       KC_F1,        KC_F2,        KC_F3,        KC_F4,         KC_F5,    KC_F6,    KC_F7,        KC_F8,        KC_F9,        KC_F10,          KC_F11,    KC_F12,    KC_NO,        KC_PSCR,   TG(2),     KC_OSTOG},
      {   KC_GRV,       KC_1,         KC_2,         KC_3,         KC_4,          KC_5,     KC_6,     KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,   KC_EQL,    KC_BSPC,      KC_INS,    KC_HOME,   KC_PGUP},
      {   KC_TAB,       KC_Q,         KC_W,         KC_E,         KC_R,          KC_T,     KC_Z,     KC_U,         KC_I,         KC_O,         KC_P,            KC_LBRC,   KC_RBRC,   KC_BSLS,      KC_DEL,    KC_END,    KC_PGDN},
      {   KC_ESC,       LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F),  KC_G,     KC_H,     RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN), KC_QUOT,   KC_NO,     KC_ENT,       KC_NO,     KC_NO,     KC_NO},
      {   KC_LSFT,      KC_NO,        KC_Y,         KC_X,         KC_C,          KC_V,     KC_B,     KC_N,         KC_M,         KC_COMM,      KC_DOT,          KC_SLSH,   KC_NO,     KC_RSFT,      KC_NO,     KC_UP,     KC_NO},
      {   KC_LCTL,      KC_LGUI,      MO(L_DEV),    KC_NO,        KC_NO,         KC_NO,    KC_SPC,   KC_NO,        KC_NO,        KC_NO,        MO(L_DEV),       KC_RGUI,   KC_RCTL,   KC_APP,       KC_LEFT,   KC_DOWN,   KC_RGHT}
    },
    [L_DEV] = {
      {   RESET,        _______,      _______,      _______,      LALT(KC_F4),   _______,  _______,  _______,      _______,      _______,      _______,         _______,   _______,   KC_NO,        _______,   _______,   _______ },
      {   _______,      _______,      _______,      _______,      _______,       _______,  _______,  _______,      _______,      _______,      _______,         _______,   _______,   LALT(KC_BSPC),_______,   _______,   _______ },
      {   LALT(KC_TAB), KC_TILD,      KC_AT,        KC_PERC,      KC_AMPR,       _______,  KC_ASTR,  KC_DIAERESIS, KC_LCBR,      KC_RCBR,      _______,         _______,   _______,   _______,      _______,   _______,   _______ },
      {   _______,      KC_EXLM,      KC_UNDS,      KC_DLR,       KC_MINUS,      KC_PLUS,  KC_PIPE,  KC_EQUAL,     KC_LPRN,      KC_RPRN,      _______,         _______,   KC_NO,     _______,      KC_NO,     KC_NO,     KC_NO },
      {   LALT(KC_LSFT),_______,      _______,      _______,      _______,       _______,  _______,  KC_LBRC,      KC_RBRC,      KC_LT,        KC_GT,           _______,   KC_NO,     _______,      KC_NO,     _______,   KC_NO },
      {   _______,      _______,      _______,      KC_NO,        KC_NO,         KC_NO,    KC_SPC,   KC_NO,        KC_NO,        KC_NO,        _______,         _______,   _______,   _______,      _______,   _______,   _______ }
    },
};

void keyboard_post_init_user(void) {
  rgblight_disable();
}

bool process_ostoggle(uint16_t keycode, bool shift) {
  if (keycode != KC_OSTOG) return true;

  if (!shift) {
    is_mac = !is_mac;
    return false;
  }

  if (is_mac) {
    tap_code(KC_A);
    tap_code(KC_P);
    tap_code(KC_P);
    tap_code(KC_L);
    tap_code(KC_E);
  } else {
    tap_code(KC_W);
    tap_code(KC_I);
    tap_code(KC_N);
  }
  return false;
}

bool process_diaeresis(uint16_t keycode, bool shift) {
  static bool diaeresis = false;

  if (keycode == KC_DIAERESIS) {
    diaeresis = !diaeresis;
    if (diaeresis && is_mac) {
      register_code(KC_RALT);
      tap_code(KC_U);
      unregister_code(KC_RALT);
    }
    return false;
  }

  if (!diaeresis) return true;


  if (is_mac) {
    diaeresis = false;
    return true;
  }

  if (keycode == KC_A || keycode == KC_O || keycode == KC_U) {
    const uint32_t u_AE = 0xC4;
    const uint32_t u_ae = 0xE4;
    const uint32_t u_UE = 0xDC;
    const uint32_t u_ue = 0xFC;
    const uint32_t u_OE = 0xD6;
    const uint32_t u_oe = 0xF6;
    if (keycode == KC_A && shift) register_unicode(u_AE);
    if (keycode == KC_A && !shift) register_unicode(u_ae);
    if (keycode == KC_U && shift) register_unicode(u_UE);
    if (keycode == KC_U && !shift) register_unicode(u_ue);
    if (keycode == KC_O && shift) register_unicode(u_OE);
    if (keycode == KC_O && !shift) register_unicode(u_oe);
    diaeresis = false;
    return false;
  } else if (IS_MOD(keycode)) {
    return true;
  } else {
    diaeresis = true;
    return true;
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!record->event.pressed) return true;
  const bool shift = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;

  keycode = keycode == LGUI_T(KC_A) ? KC_A : keycode;
  if (!process_ostoggle(keycode, shift)) { return false; }
  if (!process_diaeresis(keycode, shift)) { return false; }

  return true;
}
