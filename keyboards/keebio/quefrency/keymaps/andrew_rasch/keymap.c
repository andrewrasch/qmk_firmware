#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define FN0 0
#define FN1 1
#define FN2 2

#define O_UMLT XP(O_UMLT_L, O_UMLT_C)
#define A_UMLT XP(A_UMLT_L, A_UMLT_C)
#define U_UMLT XP(U_UMLT_L, U_UMLT_C)
#define ESZETT XP(ESZETT_L, ESZETT_C)

enum unicode_names {
  O_UMLT_L,
  O_UMLT_C,
  A_UMLT_L,
  A_UMLT_C,
  U_UMLT_L,
  U_UMLT_C,
  ESZETT_L,
  ESZETT_C,
};

const uint32_t PROGMEM unicode_map[] = {
    [O_UMLT_L]  = 0xF6,
    [A_UMLT_L]  = 0xE4,
    [U_UMLT_L]  = 0xFC,
    [A_UMLT_C]  = 0xC4,
    [O_UMLT_C]  = 0xD6,
    [U_UMLT_C]  = 0xDC,
    [ESZETT_L]  = 0xDF,
    [ESZETT_C]  = 0x1E9E,
};

 /* [FNX] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [FN0] = LAYOUT_65_with_macro(
    KC_F1,   KC_F2,   KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, KC_INS, \
    KC_F3,   KC_F4,   KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
    KC_F5,   KC_F6,   MO(FN1),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME, \
    KC_F7,   KC_F8,   KC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_UP,   KC_END, \
    KC_F9,   KC_F10,  KC_LCTL,  KC_LGUI, KC_LALT, MO(FN1), KC_SPC,           KC_BSPC, MO(FN1), KC_RALT, KC_RGUI,KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [FN2] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [FN1] = LAYOUT_65_with_macro(
    TG(FN2), _______, KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,  KC_PSCR, _______, \
    _______, _______, KC_CAPS, _______, _______, _______, _______, _______, _______, U_UMLT , KC_UP,   O_UMLT , _______, _______, _______, _______, _______, \
    _______, _______, _______, A_UMLT , ESZETT , _______, _______, KC_H   , _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_PGUP, \
    _______, _______, _______, _______, _______, _______, _______, KC_M   , _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_PGDN, \
    _______, UC_MOD , KC_MEH , _______, KC_HYPR, _______, _______,          _______, _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT
  )

};

void matrix_init_user() {
	set_unicode_input_mode(UC_WINC);
};
