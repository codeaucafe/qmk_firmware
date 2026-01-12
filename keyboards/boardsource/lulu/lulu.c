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
    return OLED_ROTATION_270;  // Left side: vertical, bottom-to-top
  } else {
    return OLED_ROTATION_90;   // Right side: vertical, top-to-bottom
  }
}

// Left OLED: "codeaucafe" reading bottom-to-top (reversed)
static void render_logo_left(void) {
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
}

// Right OLED: "codeaucafe" reading top-to-bottom
static void render_logo_right(void) {
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
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_logo_left();
  } else {
    render_logo_right();
  }
  return false;
}
#endif // OLED_ENABLE
