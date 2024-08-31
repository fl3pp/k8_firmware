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
  KC_DIAERESIS, // see process_diaeresis
  KC_ALTFALL, // see process_alt_fallthrough
  alt_______ = KC_ALTFALL
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

    // recommendation: use `set wrap` in Vim
    [L_BASE] = {
      {   KC_ESC,       KC_F1,        KC_F2,        KC_F3,        KC_F4,         KC_F5,      KC_F6,      KC_F7,        KC_F8,        KC_F9,        KC_F10,          KC_F11,      KC_F12,      KC_NO,        KC_PSCR,     TG(2),       KC_OSTOG},
      {   KC_GRV,       KC_1,         KC_2,         KC_3,         KC_4,          KC_5,       KC_6,       KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,     KC_EQL,      KC_BSPC,      KC_INS,      KC_HOME,     KC_PGUP},
      {   KC_TAB,       KC_Q,         KC_W,         KC_E,         KC_R,          KC_T,       KC_Z,       KC_U,         KC_I,         KC_O,         KC_P,            KC_LBRC,     KC_RBRC,     KC_BSLS,      KC_DEL,      KC_END,      KC_PGDN},
      {   KC_ESC,       KC_A,         KC_S,         KC_D,         KC_F,          KC_G,       KC_H,       KC_J,         KC_K,         KC_L,         KC_SCLN,         KC_QUOT,     KC_NO,       KC_ENT,       KC_NO,       KC_NO,       KC_NO},
      {   KC_LSFT,      KC_NO,        KC_Y,         KC_X,         KC_C,          KC_V,       KC_B,       KC_N,         KC_M,         KC_COMM,      KC_DOT,          KC_SLSH,     KC_NO,       KC_RSFT,      KC_NO,       KC_UP,       KC_NO},
      {   KC_LCTL,      KC_LGUI,      MO(L_DEV),    KC_NO,        KC_NO,         KC_NO,      KC_SPC,     KC_NO,        KC_NO,        KC_NO,        MO(L_DEV),       KC_RGUI,     KC_RCTL,     KC_APP,       KC_LEFT,     KC_DOWN,     KC_RGHT}
    },
    [L_DEV] = {
      {   RESET,        alt_______,   alt_______,   alt_______,   alt_______,    alt_______, alt_______, alt_______,   alt_______,   alt_______,   alt_______,      alt_______,  alt_______,  KC_NO,        alt_______,  _______,     alt_______ },
      {   alt_______,   _______,      _______,      _______,      _______,       _______,    _______,    _______,      _______,      _______,      _______,         _______,     _______,     alt_______,   alt_______,  alt_______,  alt_______ },
      {   alt_______,   KC_TILD,      KC_AT,        KC_PERC,      KC_AMPR,       _______,    KC_ASTR,    KC_DIAERESIS, KC_LCBR,      KC_RCBR,      _______,         _______,     _______,     _______,      alt_______,  alt_______,  alt_______ },
      {   alt_______,   KC_EXLM,      KC_UNDS,      KC_DLR,       KC_MINUS,      KC_PLUS,    KC_PIPE,    KC_EQUAL,     KC_LPRN,      KC_RPRN,      _______,         _______,     KC_NO,       alt_______,   KC_NO,       KC_NO,       KC_NO },
      {   alt_______,   _______,      _______,      _______,      _______,       _______,    _______,    KC_LBRC,      KC_RBRC,      KC_LT,        KC_GT,           _______,     KC_NO,       alt_______,   KC_NO,       alt_______,  KC_NO },
      {   alt_______,   alt_______,   _______,      KC_NO,        KC_NO,         KC_NO,      KC_SPC,     KC_NO,        KC_NO,        KC_NO,        _______,         alt_______,  alt_______,  alt_______,   alt_______,  alt_______,  alt_______ }
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

// MacOS US-Keyboard Style diaeresis on MacOS _and_ Windows
bool process_diaeresis(uint16_t keycode, bool shift) {
  static bool diaeresis = false;

  if (keycode == KC_DIAERESIS) {
    diaeresis = !diaeresis;
    if (diaeresis && is_mac) {
      register_mods(MOD_MASK_ALT);
      tap_code(KC_U);
      unregister_mods(MOD_MASK_ALT);
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
  } else if (!IS_MOD(keycode)) {
    diaeresis = true;
  }

  return true;
}

// use KC_ALTFALL or alt_______ to triger a fallthrough to the DEFAULT layer
// with ALT being activated
// inspiration: https://www.reddit.com/r/olkb/comments/97jx68/qmk_how_to_mimic_kc_trns_and_mt_in_process_record/
bool process_alt_fallthrough(uint16_t keycode, keyrecord_t *record) {
  if (keycode != KC_ALTFALL) return true;

  uint16_t fallthrough = keymap_key_to_keycode(biton32(default_layer_state), record->event.key);

  if (record->event.pressed) {
	register_mods(MOD_MASK_ALT);
    register_code(fallthrough);
  } else {
    unregister_code(fallthrough);
	// unregistration of MOD_MASK_ALT in process_alt_fallthrough_layer
  }
  return false;
}

bool process_alt_fallthrough_layer(layer_state_t * state) {
  if (get_highest_layer(*state) < L_DEV) {
    unregister_mods(MOD_MASK_ALT);
  }
  return true;
}

bool process_shift_backspace(uint16_t keycode, keyrecord_t *record, bool shift) {
  if (keycode != KC_BSPC) return true;

  static bool shift_del_active = false;
  uint8_t mod_state = get_mods();

  if (record->event.pressed) {
    if (mod_state & MOD_MASK_SHIFT) {
      del_mods(MOD_MASK_SHIFT);
      register_code(KC_DEL);
      shift_del_active = true;
      set_mods(mod_state); // reaply mod to keep shifts working after tap
      return false;
    }
  } else {
    if (shift_del_active) {
      unregister_code(KC_DEL);
      shift_del_active = false;
      return false;
    }
  }

  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  const bool shift = (get_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT;

  if (!process_shift_backspace(keycode, record, shift)) { return false; }
  if (!process_alt_fallthrough(keycode, record)) { return false; }
  if (!record->event.pressed) return true; // the following processors assume keydown
  if (!process_diaeresis(keycode, shift)) { return false; }
  if (!process_ostoggle(keycode, shift)) { return false; }

  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  if (!process_alt_fallthrough_layer(&state)) { return false; }
  return state;
}
