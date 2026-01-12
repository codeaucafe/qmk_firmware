#include QMK_KEYBOARD_H
#include "wt_rgb_backlight_keycodes.h"

enum layers {
    _BASE,
    _SECOND,
    _RGB
};

#define BASE TO(_BASE)
#define SECOND TO(_SECOND)
#define RGB TO(_RGB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base layer
    [_BASE] = LAYOUT(
        KC_LSFT, KC_F9,   KC_F2,
        KC_LALT, KC_LGUI, EF_INC
    ),

    // Function layer 1
    [_SECOND] = LAYOUT(
        EF_INC, KC_F9,   KC_F2,
        EF_DEC, KC_3, RGB

    ),

    // Function layer 2 (RGB controls)
    [_RGB] = LAYOUT(
        RGB_TOG, RGB_MOD, RGB_RMOD,
        EF_INC,  EF_DEC,  BASE
    )
};
