/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "rgb_matrix_map.h"

#define INDICATOR_HSV 160, 255, 255
#define INDICATOR_UNDERGLOW_HSV HSV_GOLD

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, _______, TG(2),   TG(3),   _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           KC_INS,
        _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, RGB_VAI, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_RMOD, RGB_VAD, RGB_MOD
    ),

    [2] = LAYOUT(
        KC_PWR,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLEP,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, _______, EE_CLR,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
    ),

};
// clang-format on

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case 0:
            clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD); // Base: Volume
            break;

        case 1:
            clockwise ? tap_code(KC_WH_U) : tap_code(KC_WH_D); // Fn: Scroll
            break;

        default:
            break;
    }

    return true;
}
#endif // ENCODER_ENABLE


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t val = rgb_matrix_get_val();
    HSV indicator_hsv = {INDICATOR_HSV};
    HSV indicator_underglow_hsv = {INDICATOR_UNDERGLOW_HSV};
    indicator_hsv.v = val;
    indicator_underglow_hsv.v = val;
    RGB indicator_rgb = hsv_to_rgb(indicator_hsv);
    RGB indicator_underglow_rgb = hsv_to_rgb(indicator_underglow_hsv);

    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW)
                rgb_matrix_set_color(i, indicator_underglow_rgb.r, indicator_underglow_rgb.g, indicator_underglow_rgb.b);
            else
                rgb_matrix_set_color(i, indicator_rgb.r, indicator_rgb.g, indicator_rgb.b);
        }

        rgb_matrix_set_color(LED_F12, indicator_rgb.r, indicator_rgb.g, indicator_rgb.b);
    }

    if (IS_LAYER_ON(1)) {
        rgb_matrix_set_color(LED_FN, indicator_rgb.r, indicator_rgb.g, indicator_rgb.b);
        rgb_matrix_set_color(LED_F1, indicator_rgb.r, indicator_rgb.g, indicator_rgb.b);
    }

    if (IS_LAYER_ON(2)) {
        rgb_matrix_set_color(LED_F2, indicator_rgb.r, indicator_rgb.g, indicator_rgb.b);
    }

    if (IS_LAYER_ON(3)) {
        rgb_matrix_set_color(LED_F3, indicator_rgb.r, indicator_rgb.g, indicator_rgb.b);
    }

    return false;
}
