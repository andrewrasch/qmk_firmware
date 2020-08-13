#include "rgb_utils.h"

uint8_t master_hue;
uint8_t master_sat;
uint8_t master_val;

void sethsv_master(uint8_t h, uint8_t s, uint8_t v) {
    rgblight_sethsv_range(h, s, v, 0, RGBLED_NUM);
    master_hue = h;
    master_sat = s;
    master_val = v;
}

void sethsv_slave(uint8_t h, uint8_t s, uint8_t v) {
    rgblight_sethsv_noeeprom(h, s, v);
    rgblight_sethsv_range(master_hue, master_sat, master_val, 0, RGBLED_NUM);
}
