#include QMK_KEYBOARD_H

#ifdef ENCODER_ENABLE
#    include "encoder_utils.h"
#endif

extern keymap_config_t keymap_config;

enum custom_keycodes {
    ENC_L = SAFE_RANGE,
    ENC_R,
};

enum layers { BASE, NOOB, FN1, GER, FN2 };

#define O_UMLT XP(O_UMLT_L, O_UMLT_C)
#define A_UMLT XP(A_UMLT_L, A_UMLT_C)
#define U_UMLT XP(U_UMLT_L, U_UMLT_C)
#define ESZETT XP(ESZETT_L, ESZETT_C)
#define FN1BSP LT(FN1, KC_BSPC)

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
  [BASE] = LAYOUT_65_with_macro(
    ENC_L,   KC_GRV,  KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC, ENC_R, \
    KC_F1,   KC_F2,   KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
    KC_F3,   KC_F4,   MO(FN1),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,  KC_HOME, \
    KC_F5,   KC_F6,   KC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, KC_UP,   KC_END, \
    KC_F7,   KC_F8,   KC_LCTL,  KC_LGUI, KC_LALT, MO(GER), KC_SPC,           _______, KC_BSPC, KC_RALT, KC_RGUI,KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [NOOB] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RSFT, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, KC_SPC, _______, _______, _______, _______, _______, _______
  ),

  [FN1] = LAYOUT_65_with_macro(
    _______, TG(NOOB),KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_PSCR, KC_PSCR, _______, \
    _______, TG(FN2), KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______ , KC_INS, \
    _______, _______, _______, _______, _______, _______, _______, KC_H   , _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_PGUP, \
    _______, _______, _______, _______, _______, _______, _______, KC_M   , _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, KC_PGDN, \
    _______, _______, _______, KC_MEH,  KC_HYPR, _______, _______,          _______, KC_DEL , _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT
  ),

  [GER] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, A_UMLT , _______, _______, _______, _______, U_UMLT,  _______, _______, _______, O_UMLT , _______, _______, _______, _______, \
    _______, _______, _______, _______, ESZETT , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [FN2] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, RGB_TOG, RGB_MOD,RGB_RMOD, RGB_HUI, RGB_VAI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    RESET,   UC_MOD,  _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )

};

void matrix_init_user() {
#ifdef ENCODER_ENABLE
    encoder_utils_init();
#endif
};

void keyboard_post_init_user(void) {
#ifdef ENCODER_ENABLE
    encoder_rgb_init();
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool reverse = get_mods() & MOD_MASK_SHIFT;
    switch (keycode) {
#ifdef ENCODER_ENABLE
        case ENC_L:
            if (record->event.pressed) {
                cycle_encoder_mode(true, reverse);
            }
            break;
        case ENC_R:
            if (record->event.pressed) {
                cycle_encoder_mode(false, reverse);
            }
            break;
#endif
    }
    return true;
}

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        encoder_action(get_encoder_mode(true), clockwise);
    } else if (index == 1) {
        encoder_action(get_encoder_mode(false), clockwise);
    }
}
#endif
