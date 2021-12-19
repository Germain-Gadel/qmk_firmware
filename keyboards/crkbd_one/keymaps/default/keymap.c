/* Copyright 2021 germain-gadel
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

enum crkbd_one_tap_dances {
  TD_Q_ESC,
  TD_P_BSPC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
        TD(TD_Q_ESC), KC_W, KC_E, KC_R, KC_T,                               KC_Y, KC_U, KC_I, KC_O, TD(TD_P_BSPC),
        LT(5,KC_A), KC_S, KC_D, KC_F, KC_G,                                 KC_H, KC_J, KC_K, KC_L, KC_SCLN,
        LSFT_T(KC_Z), LCTL_T(KC_X), LGUI_T(KC_C), LALT_T(KC_V), KC_B,       KC_N, RALT_T(KC_M), RGUI_T(KC_COMM), RCTL_T(KC_DOT), RSFT_T(KC_SLSH),
                            LT(1,KC_ESC), LT(2,KC_TAB), KC_SPC,         KC_BSPC, LT(3,KC_ENT), LT(4,KC_DEL)),

	[1] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                           KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
        KC_NO, KC_GRV, KC_LBRC, KC_RBRC, KC_BSLS,                    KC_F11, KC_F12, KC_NO, KC_NO, KC_QUOT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                   KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_NO, KC_NO, KC_TRNS,            KC_TRNS, KC_NO, KC_NO),

	[2] = LAYOUT(
        KC_TRNS, KC_7, KC_8, KC_9, KC_0,                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_4, KC_5, KC_6, KC_EQL,                           KC_NO, KC_NO, KC_NO, KC_NO, KC_QUOT,
        KC_TRNS, KC_1, KC_2, KC_3, KC_MINS,                          KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_NO, KC_NO, KC_TRNS,            KC_TRNS, KC_NO, KC_NO),

	[3] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                           KC_NO, KC_NO, KC_UP, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                           KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_QUOT,
        KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, KC_NO,                   KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                        KC_NO, KC_NO, KC_TRNS,            KC_TRNS, KC_NO, KC_NO),

	[4] = LAYOUT(
        RESET, KC_NO, KC_NO, KC_NO, KC_NO,                           KC_MS_BTN3, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                           KC_NO, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_QUOT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,                   KC_MRWD, KC_MFFD, KC_MPRV, KC_MNXT, KC_MUTE,
                                        KC_NO, KC_NO, KC_TRNS,            KC_MPLY, KC_MPLY, KC_NO),

	[5] = LAYOUT(
        KC_NO, KC_NO, KC_PGUP, KC_PGDN, KC_PSCR,                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_CAPS, KC_HOME, KC_END, KC_SLCK,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_LSFT, KC_LCTL, KC_INS, KC_DEL, KC_PAUS,                   KC_NO, KC_RALT, KC_RGUI, KC_RCTL, KC_RSFT,
                                        KC_NO, KC_NO, KC_TRNS,            KC_BSPC, KC_NO, KC_NO)
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_P_BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_BSPC)
};