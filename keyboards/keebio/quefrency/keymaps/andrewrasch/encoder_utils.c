#include "encoder_utils.h"
#include "rgb_utils.h"

void encoder_utils_init(void) {
    encoder_left_mode  = ENC_MODE_HISTORY_SCRUB;
    encoder_right_mode = ENC_MODE_WORD_NAV;
}

void set_encoder_color(bool left, encoder_mode_t mode) {
    switch (mode) {
        case ENC_MODE_VOLUME:
            left ? sethsv_master(HSV_PURPLE) : sethsv_slave(HSV_PURPLE);
            break;
        case ENC_MODE_WORD_NAV:
            left ? sethsv_master(HSV_RED) : sethsv_slave(HSV_RED);
            break;
        case ENC_MODE_UP_DOWN:
            left ? sethsv_master(HSV_GREEN) : sethsv_slave(HSV_GREEN);
            break;
        case ENC_MODE_PAGING:
            left ? sethsv_master(HSV_BLUE) : sethsv_slave(HSV_BLUE);
            break;
        case ENC_MODE_HISTORY_SCRUB:
            left ? sethsv_master(HSV_CYAN) : sethsv_slave(HSV_CYAN);
            break;
        default:
            break;
    }
}

void encoder_rgb_init(void) {
    set_encoder_color(true, encoder_left_mode);
    set_encoder_color(false, encoder_right_mode);
}

void set_encoder_mode(bool left, encoder_mode_t mode) {
    if (left) {
        encoder_left_mode = mode;
    } else {
        encoder_right_mode = mode;
    }
    set_encoder_color(left, mode);
}

encoder_mode_t get_encoder_mode(bool left) {
    if (left) {
        return encoder_left_mode;
    } else {
        return encoder_right_mode;
    }
}

void cycle_encoder_mode(bool left, bool reverse) {
    encoder_mode_t mode = get_encoder_mode(left);
    if (reverse) {
        mode = (mode == 0) ? (_ENC_MODE_LAST - 1) : (mode - 1);
    } else {
        mode = (mode == (_ENC_MODE_LAST - 1)) ? 0 : (mode + 1);
    }
    set_encoder_mode(left, mode);
}

void encoder_action_volume(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

void encoder_action_word_nav(uint8_t clockwise) {
    if (clockwise) {
        tap_code16(C(KC_RIGHT));
    } else {
        tap_code16(C(KC_LEFT));
    }
}

void encoder_action_history_scrub(uint8_t clockwise) {
    if (clockwise) {
        tap_code16(C(S(KC_Z)));
    } else {
        tap_code16(C(KC_Z));
    }
}

void encoder_action_up_down(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_DOWN);
    } else {
        tap_code(KC_UP);
    }
}

void encoder_action_paging(uint8_t clockwise) {
    if (clockwise) {
        tap_code(KC_PGDN);
    } else {
        tap_code(KC_PGUP);
    }
}

void encoder_action(encoder_mode_t mode, uint8_t clockwise) {
    switch (mode) {
        case ENC_MODE_VOLUME:
            encoder_action_volume(clockwise);
            break;
        case ENC_MODE_WORD_NAV:
            encoder_action_word_nav(clockwise);
            break;
        case ENC_MODE_HISTORY_SCRUB:
            encoder_action_history_scrub(clockwise);
            break;
        case ENC_MODE_UP_DOWN:
            encoder_action_up_down(clockwise);
            break;
        case ENC_MODE_PAGING:
            encoder_action_paging(clockwise);
            break;
        default:
            encoder_action_volume(clockwise);
    }
}
