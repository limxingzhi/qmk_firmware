/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum layers{
    MAC_BASE,
    WIN_BASE,
    MAC_FN1,
    WIN_FN1,
    FN2,
};

// // Define custom keycodes starting from SAFE_RANGE
// enum custom_keycodes {
//     HRM_S = SAFE_RANGE,  // Custom keycode for LGUI + F
//     HRM_D,
//     HRM_F,
//     HRM_J,
//     HRM_K,
//     HRM_L,
// };
//
// // Define a struct to hold key and modifier information
// typedef struct {
//     uint16_t keycode; // Keycode for the tap
//     uint8_t modifier; // Modifier to hold
// } key_modifier_pair_t;
//
// // Define an array of key/modifier pairs
// key_modifier_pair_t key_modifier_pairs[] = {
//     { KC_S, MOD_LALT },
//     { KC_D, MOD_LCTL },
//     { KC_F, MOD_LGUI },
//     { KC_J, MOD_LGUI },
//     { KC_K, MOD_LCTL },
//     { KC_L, MOD_LALT },
// };
//
// // Handle key press/release logic in process_record_user
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     static uint16_t key_timer; // Timer for tap duration
//
//     // Check if the keycode is one of our custom keycodes
//     for (size_t i = 0; i < sizeof(key_modifier_pairs) / sizeof(key_modifier_pair_t); i++) {
//         if (keycode == (HRM_S + i)) { // Adjusted to match the enum
//             if (record->event.pressed) {
//                 // Start the timer on key press
//                 key_timer = timer_read();
//                 // On key press, hold the specified modifier
//                 register_mods(key_modifier_pairs[i].modifier);
//             } else {
//                 // On key release, unregister the modifier
//                 unregister_mods(key_modifier_pairs[i].modifier);
//
//                 // Check if it was a tap or hold
//                 if (timer_elapsed(key_timer) < TAPPING_TERM) {
//                     // If tapped, send the corresponding key press
//                     tap_code(key_modifier_pairs[i].keycode);
//                 }
//             }
//             return false;  // Prevent further processing of this keycode
//         }
//     }
//
//     return true;  // Process other keycodes normally
// }

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_69_ansi(
        KC_ESC,  KC_1,KC_2, KC_3,              KC_4,                 KC_5,    KC_6,      KC_7,                KC_8,              KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,KC_W, KC_E,              KC_R,                 KC_T,    KC_Y,      KC_U,                KC_I,              KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_ESC , MT(MOD_LSFT,KC_A),MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), MT(MOD_LGUI, KC_F),    LT(MAC_FN1,KC_G),   LT(MAC_FN1,KC_H), MT(MOD_RGUI, KC_J), MT(MOD_RCTL,KC_K),MT(MOD_RALT,KC_L),MT(MOD_RSFT,KC_SCLN),KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,      KC_Z, KC_X,              KC_C,                 KC_V,    LT(FN2,KC_B),      LT(FN2,KC_B),          LT(FN2,KC_N),       KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPTN, OSL(MAC_FN1),          KC_SPC,           KC_LGUI, KC_ESC,       KC_SPC,           OSL(FN2),           KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_69_ansi(
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,     KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_CAPS, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,              KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,           KC_HOME,
        KC_LSFT,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,     KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN,  KC_LALT,           KC_SPC,           MO(WIN_FN1), MO(FN2),       KC_SPC,            KC_RALT,            KC_LEFT, KC_DOWN, KC_RGHT),

    [MAC_FN1] = LAYOUT_69_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_MCTL, KC_LPAD, BL_DOWN, BL_UP,    KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          BL_TOGG,
        _______, _______,  _______,  _______, _______, _______, KC_BSLS,  KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,   _______,  _______,  _______,          _______,
        KC_CAPS, BL_STEP,  BL_UP,    _______, _______, _______,           KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, KC_PGDN,  KC_END,   _______,          _______,
        KC_CAPS,           _______,  BL_DOWN, _______, _______, _______,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           KC_BSPC,          _______,  KC_GRV ,          KC_BSPC,           _______,            _______, _______, _______),

    [WIN_FN1] = LAYOUT_69_ansi(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FILE, BL_DOWN, BL_UP,    KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          BL_TOGG,
        _______, BT_HST1,  BT_HST2,  BT_HST3, _______, _______, _______,  _______, KC_APP,  KC_SCRL, KC_INS,   KC_PGUP,  _______,  _______,          _______,
        BL_TOGG, BL_STEP,  BL_UP,    _______, _______, _______,           _______, _______, _______, KC_PSCR,  KC_PGDN,  KC_END,   _______,          _______,
        _______,           _______,  BL_DOWN, _______, _______, _______,  _______, NK_TOGG, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______),

    [FN2] = LAYOUT_69_ansi(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,          _______,
        _______, BT_HST1,  BT_HST2,  BT_HST3, _______, _______, _______,  _______, _______, KC_VOLD, KC_VOLU,  _______,  _______,  _______,          _______,
        _______, _______,  _______,  _______, _______, _______,           _______, _______, _______, _______,  _______,  _______,  _______,          _______,
        _______,           _______,  _______, _______, _______, BAT_LVL,  BAT_LVL, _______, _______, _______,  _______,  _______,  _______, _______,
        _______, _______,  _______,           _______,          _______,  _______,          _______,           _______,            _______, _______, _______)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN1]  = { ENCODER_CCW_CW(BL_DOWN, BL_UP)},
    [WIN_FN1]  = { ENCODER_CCW_CW(BL_DOWN, BL_UP)},
    [FN2]      = { ENCODER_CCW_CW(_______, _______)},
};
#endif // ENCODER_MAP_ENABLE
