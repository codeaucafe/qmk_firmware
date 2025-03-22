#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Layer 0: Base Layer
    [0] = LAYOUT(
        KC_LSFT,    KC_F7,    KC_F8,
        KC_LGUI,    KC_F2,    TG(1)    // Bottom right key toggles to Layer 1 (RGB controls)
    ),

    // Layer 1: RGB Control Layer
    [1] = LAYOUT(
        RGB_TOG, RGB_RMOD, RGB_MOD,  // RGB Toggle, Mode cycle backward, Mode cycle forward
        KC_BRID, KC_BRIU, TG(2)      // Hue increase, Brightness increase, Toggle to Layer 2
    ),

    // Layer 2: Function Keys - keeping this the same
    [2] = LAYOUT(
        RGB_SAI,   RGB_HUI,   KC_F3,    // Sat+, Hue+
        RGB_SAD,   RGB_HUD,   TG(3)     // Sat-, Hue-, Toggle to Layer 3
    ),

    // Layer 3: Media Controls - modified as requested
    [3] = LAYOUT(
        KC_MPLY, KC_VOLD, KC_VOLU,  // Play/Pause instead of mute in top left
        KC_MPRV, KC_MNXT, TG(0)     // Prev track, Next track, Toggle back to Layer 0
    )
};
