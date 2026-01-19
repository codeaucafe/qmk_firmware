// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H
#include "encoder.h"

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;  // Master (left): vertical, bottom-to-top
  } else {
    return OLED_ROTATION_90;   // Slave (right): vertical, top-to-bottom
  }
}

// Left OLED: "codeaucafe" reading bottom-to-top, centered
static void render_logo_left(void) {
  // 3 blank lines for centering (bottom padding)
  oled_write_ln(" ", false);
  oled_write_ln(" ", false);
  oled_write_ln(" ", false);
  // Text (reversed so it reads bottom-to-top)
  oled_write_ln("e", false);
  oled_write_ln("f", false);
  oled_write_ln("a", false);
  oled_write_ln("c", false);
  oled_write_ln("u", false);
  oled_write_ln("a", false);
  oled_write_ln("e", false);
  oled_write_ln("d", false);
  oled_write_ln("o", false);
  oled_write_ln("c", false);
  // 3 blank lines for centering (top padding)
  oled_write_ln(" ", false);
  oled_write_ln(" ", false);
  oled_write_ln(" ", false);
}

// Right OLED: "codeaucafe" reading top-to-bottom, centered
static void render_logo_right(void) {
  // 3 blank lines for centering (top padding)
  oled_write_ln(" ", false);
  oled_write_ln(" ", false);
  oled_write_ln(" ", false);
  // Text
  oled_write_ln("c", false);
  oled_write_ln("o", false);
  oled_write_ln("d", false);
  oled_write_ln("e", false);
  oled_write_ln("a", false);
  oled_write_ln("u", false);
  oled_write_ln("c", false);
  oled_write_ln("a", false);
  oled_write_ln("f", false);
  oled_write_ln("e", false);
  // 3 blank lines for centering (bottom padding)
  oled_write_ln(" ", false);
  oled_write_ln(" ", false);
  oled_write_ln(" ", false);
}

bool oled_task_user(void) {
  oled_clear();
  if (is_keyboard_master()) {
    render_logo_left();
  } else {
    render_logo_right();
  }
  return false;
}
#endif // OLED_ENABLE
