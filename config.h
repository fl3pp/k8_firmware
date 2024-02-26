#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x3434
#define PRODUCT_ID      0xFE0E
#define DEVICE_VER		0x0001

// tapping term in ms (how long until a tap becomes a hold)
#define TAPPING_TERM 200
// Prevent rollover (n down, o down, n up, o up) to trigger mods, if duration lower than tapping term
#define IGNORE_MOD_TAP_INTERRUPT
// Undercut tapping term (n down, o down, o up, n up)
#define TAPPING_FORCE_HOLD
// SEE: https://precondition.github.io/home-row-mods#using-home-row-mods-with-qmk

// requires WinCompose installed with F13 trigger 
#define UNICODE_SELECTED_MODES UC_WINC
#define UNICODE_KEY_WINC KC_F13
