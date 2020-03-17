#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  O_UMLT,
  A_UMLT,
  U_UMLT,
  ESZETT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_F1,   KC_F2,   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_INS, \
    KC_F3,   KC_F4,   KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
    KC_F5,   KC_F6,   MO(_FN1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME, \
    KC_F7,   KC_F8,   KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,   KC_END, \
    KC_F9,   KC_F10,  KC_LCTL,  KC_LGUI, KC_LALT, MO(_FN1),KC_SPC,           KC_SPC,  MO(_FN1),KC_RALT, KC_RGUI,KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT 
  ),

  [_FN1] = LAYOUT_65_with_macro(
    _______, _______, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,  KC_PSCR, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, U_UMLT , _______, O_UMLT , _______, _______, _______, _______, _______, \
    _______, _______, _______, A_UMLT , ESZETT , _______, _______, KC_H   , _______, _______, _______, _______, _______, _______, _______, KC_PGUP, \
    _______, _______, KC_RSFT, _______, _______, _______, _______, KC_M   , _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_PGDN, \
    _______, _______, KC_TILD, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case O_UMLT:
      if (record->event.pressed) {
        SEND_STRING(SS_RWIN("\"o"));
      } else {
      }
      break;
	case A_UMLT:
      if (record->event.pressed) {
        SEND_STRING(SS_RWIN("\"a"));
      } else {
      }
      break;
    case U_UMLT:
      if (record->event.pressed) {
        SEND_STRING(SS_RWIN("\"u"));
      } else {
      }
      break;
    case ESZETT:
      if (record->event.pressed) {
        SEND_STRING(SS_RWIN("ss"));
      } else {
      }
      break;
  }
  return true;
};
