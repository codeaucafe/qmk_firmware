// Copyright 2022 Cole Smith <cole@boadsource.xyz>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _SUPER,
    _RAISE,
    _MOUSE,
    _RGB
};

#define SUPER MO(_SUPER)
#define RAISE MO(_RAISE)
#define MOUSE MO(_MOUSE)
#define RGB MO(_RGB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+----- |
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | \|   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+----- |
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ;:  |  '"  |
 * |------+------+------+------+------+------|   `~  |    | Enter |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,<  |  .>  |  ?/  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | RGB  | LAlt | LGUI | /SUPER  /       \Space \  |RAISE | RGUI | RGB  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,   KC_GRV, KC_ENT,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        RGB, KC_LALT, KC_LGUI, SUPER,      KC_SPC, RAISE, KC_RGUI, RGB
),
/* SUPER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Pwr  |Pwr Dn| Sleep| Wake | XXXX | XXXX |                    |  \|  |  `~  |  }   |  -_  |  =+  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Tab | Tab  | ESC  |Enter |LCTRL |  {   |                    |  _   |  Tab |  Up  |  {[  |  ]}  |  \|  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|LShift| LGUI | LAlt |BackSP|LCTRL |-------.    ,-------|  Z   | Left | Down |Right |   =  |Enter |
 * |------+------+------+------+------+------| CAPS  |    |   )   |------+------+------+------+------+------|
 * |LCTRL |LCTRL | Home |Pg Up |Pg Dwn| End  |-------|    |-------|   B  |   V  |   C  |   X  |   Z  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |QK_BOOT | LAlt |LGUI  | /Trans  /       \Space \  |Del   | TGUI |XXXX |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_SUPER] = LAYOUT(
  KC_KB_POWER, KC_PWR,   KC_SLEP,  KC_WAKE,  KC_NO,    KC_NO,                         KC_BSLS,  KC_GRV,   KC_RCBR,  KC_MINS,  KC_EQL,  KC_BSPC,
  KC_TAB,      KC_TAB,   KC_ESC,   KC_ENT,   KC_LCTL,  KC_LCBR,                       KC_UNDS,  KC_TAB,   KC_UP,    KC_LBRC,  KC_RBRC, KC_TRNS,
  KC_LSFT,     KC_LSFT,  KC_LGUI,  KC_LALT,  KC_BSPC,  KC_LCTL,                       KC_Z,     KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_EQL,  KC_ENT,
  KC_LCTL,     KC_LCTL,  KC_HOME,  KC_PGUP,  KC_PGDN,  KC_END,   KC_CAPS,  KC_RPRN,   KC_B,     KC_V,     KC_C,     KC_X,     KC_Z,    KC_RSFT,
                                   QK_BOOT, KC_LALT, KC_LGUI, KC_TRNS,      KC_SPC, KC_DEL, KC_RGUI, KC_NO
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  | TAB  | XXXX |  (   |   )  | TAB  |                    | MUTE | VOLU |  Up  |_MOUSE|ENTER | CAPS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|LShift| DEL  |  [   |   ]  |  `~  |-------.    ,-------| VOLD | Left | Down |Right |RShift|Enter |
 * |------+------+------+------+------+------|  BRID |    | BRIU  |------+------+------+------+------+------|
 * |LCTRL |LCTRL | MRWD | MPLY | MFFD | MSTP |-------|    |-------| End  |Pg Dwn|Pg Up | Home |RShift|RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |MS_BT2| LAlt | LGUI | /BackSP /       \Trans \  |Trans |Trans | QK_BOOT |
 *                   |      |      |      |/       /         \      \ |      |      |         |
 *                   `----------------------------'           '------''-----------------------'
 */

[_RAISE] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,    KC_F6,                         KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,
  KC_TAB,  KC_TAB,  KC_NO,   KC_LPRN,  KC_RPRN,  KC_TAB,                        KC_MUTE,  KC_VOLU,  KC_UP,   MOUSE,    KC_ENT,   KC_CAPS,
  KC_LSFT, KC_LSFT, KC_DEL,  KC_LBRC,  KC_RBRC,  KC_GRV,                        KC_VOLD,  KC_LEFT,  KC_DOWN, KC_RGHT,  KC_RSFT,  KC_ENT,
  KC_LCTL, KC_LCTL, KC_MRWD, KC_MPLY,  KC_MFFD,  KC_MSTP,   KC_BRID, KC_BRIU,   KC_END,   KC_PGDN,  KC_PGUP, KC_HOME,  KC_RSFT,  KC_RSFT,
                               KC_NO, KC_LALT, KC_LGUI, KC_BSPC,      KC_TRNS, KC_TRNS, KC_TRNS, QK_BOOT
),
/* MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |                    | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | XXXX | XXXX |MS_W_D| MS_U |MS_W_U| XXXX |                    | XXXX | XXXX | XXXX |Trans |LShift| XXXX |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | XXXX |MS_BT2| MS_L | MS_D | MS_R | LAlt |-------.    ,-------| XXXX | XXXX | LGUI | XXXX | XXXX | LAlt |
 * |------+------+------+------+------+------|  XXXX |    | XXXX  |------+------+------+------+------+------|
 * | XXXX | XXXX |MS_W_R|MS_BT3|MS_W_L| XXXX |-------|    |-------| XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | XXXX | XXXX |LCTRL | / MS_BT1/       \ XXXX \  |Trans | XXXX | XXXX |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_MOUSE] = LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                     KC_NO,  KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,
  KC_NO,   KC_NO,   KC_WH_D, KC_MS_U,  KC_WH_U,  KC_NO,                     KC_NO,  KC_NO,  KC_NO,   KC_TRNS,  KC_LSFT,  KC_NO,
  KC_NO,   KC_BTN2, KC_MS_L, KC_MS_D,  KC_MS_R,  KC_LALT,                   KC_NO,  KC_NO,  KC_LGUI, KC_NO,    KC_NO,    KC_LALT,
  KC_NO,   KC_NO,   KC_WH_R, KC_BTN3,  KC_WH_L,  KC_NO,    KC_NO, KC_NO,    KC_NO,  KC_NO,  KC_NO,   KC_NO,    KC_NO,    KC_NO,
                                  KC_NO, KC_NO, KC_LCTL, KC_BTN1,    KC_NO, KC_TRNS, KC_NO, KC_NO
),

/* RGB
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |                    | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |                    | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |-------.    ,-------|RGBMOD|BRGHT+| SAT+ | HUE+ | XXXX | XXXX |
 * |------+------+------+------+------+------|  XXXX |    |RGBTOG |------+------+------+------+------+------|
 * | XXXX | XXXX | XXXX | XXXX | XXXX | XXXX |-------|    |-------|RGBRMOD|BRGHT-| SAT- | HUE- | XXXX | XXXX |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | XXXX | XXXX | XXXX | /  XXXX /       \ XXXX \   XXXX  | XXXX | XXXX |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RGB] = LAYOUT(
  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                     KC_NO,    KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,                     RGB_MOD,  RGB_VAI, RGB_SAI, RGB_HUI,    KC_NO,    KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,    KC_NO, RGB_TOG,  RGB_RMOD, RGB_VAD, RGB_SAD, RGB_HUD,    KC_NO,    KC_NO,
                                  KC_NO, KC_NO, KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO
)
};

//layer_state_t layer_state_set_user(layer_state_t state) {
//   return update_tri_layer_state(state, _SUPER, _RAISE, _MOUSE, _RGB,);
//}
