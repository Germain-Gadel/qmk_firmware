/* Copyright 2015-2021 Jack Humbert
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
#include "muse.h"

enum layers {
    _QWERTY,
    _NUM,
    _SYM,
    _ARROWS,
    _MEDIA,
    _NAV
};

#define F_SYM LT(_SYM, KC_ESC)
#define F_NUM LT(_NUM, KC_TAB)
#define F_ARR MO(_ARROWS)
#define F_ROW MO(_FROW)
#define F_MED LT(_MEDIA, KC_ENT)
#define SFT_Z LSFT_T(KC_Z)
#define SFT_BC LSFT_T(KC_LBRC)
#define CTL_X LCTL_T(KC_X)
#define CTL_BC LCTL_T(KC_RBRC)
#define LGUIT_C LGUI_T(KC_C)
#define ALT_V LALT_T(KC_V)
#define ALT_M RALT_T(KC_M)
#define ALT_F12 RALT_T(KC_F12)
#define GUI_COMM RGUI_T(KC_COMM)
#define CLT_DOT RCTL_T(KC_DOT)
#define SFT_SLH RSFT_T(KC_SLSH)
#define NAV_A LT(_NAV, KC_A)
#define M_CTRL OSM()

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '  |   \  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  Up  |SEnter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl |F_SYM |F_NUM | Space| Bksp | RAlt |F_ROW |F_MED | Left | Down |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,      KC_U,    KC_I,     KC_O,    KC_P,     SFT_BC,  CTL_BC,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,      KC_J,    KC_K,     KC_L,    KC_SCLN,  KC_QUOT, KC_BSLS,
    SFT_Z,   CTL_X,   LGUIT_C, ALT_V,   KC_B,    KC_N,      ALT_M,   GUI_COMM, CLT_DOT, SFT_SLH,  KC_UP,   KC_SFTENT,
    _______, KC_LCTL, F_SYM,   F_NUM,,  KC_SPC,  KC_BSPC,   KC_RALT, F_FROW,   F_MED,   KC_LEFT,  KC_DOWN, KC_RGHT
),

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |   0  |   7  |   8  |   9  |      |      |      |  F1  |  F2  |  F3  |  F4  |  F5  |
 * |------+------+------+------+------|------+------|------+------+------+------+------|
 * |      |   4  |   5  |   6  |   =  |      |      |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   1  |   2  |   3  |   -  |      |      |  F11 |  F12 |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   0  |   .  |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NUM] = LAYOUT_planck_grid(
    KC_0,     KC_7,  KC_8,  KC_9,   KC_TRNS,   _______, _______,  KC_F1,  KC_F2,   KC_F3,  KC_F4,   KC_F5,
    KC_TRNS,  KC_4,  KC_5,  KC_6,   KC_EQUAL,  _______, _______,  KC_F6,  KC_F7,   KC_F8,  KC_F9,   KC_F10,
    KC_TRNS,  KC_1,  KC_2,  KC_3,   KC_MINUS,  _______, _______,  KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_0, KC_PDOT, KC_TRNS, KC_TRNS, _______, _______, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* Symbols
 * ,-----------------------------------------------------------------------------------.
 * |   `  |      |   _  |   +  |   \  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   {  |   }  |   -  |   =  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   [  |   ]  |   (  |   )  |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYM] = LAYOUT_planck_grid(
    KC_GRV,   KC_TRNS,  KC_UNDS,  KC_PLUS,   KC_BSLS,  _______, _______,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_LCBR,  KC_RCBR,  KC_MINUS, KC_EQUAL,  KC_QUOT,  _______, _______,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_QUOT,
    SFT_BC,   CTL_BC,   KC_LPRN,  KC_RPRN,   KC_TRNS,  _______, _______,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,  _______, _______,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS
),

/* Media layer
 * ,-----------------------------------------------------------------------------------.
 * |RESET |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |PTrack| Vol+ |NTrack|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      | Play | Mute |      | Prev | Vol- | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_MEDIA] = LAYOUT_planck_grid(
    RESET,    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, _______, _______, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, _______, _______, KC_TRNS,  KC_TRNS,  KC_MRWD,  KC_VOLU,   KC_MFFD,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, _______, _______, KC_TRNS,  KC_TRNS,  KC_MRWD,  KC_VOLU,   KC_MFFD,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, _______, _______, KC_MPLY,  KC_MUTE,  KC_MPRV,  KC_VOLD,   KC_MNXT
),

/* Function layer
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_FROW] = LAYOUT_planck_grid(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
),
/* Nav
 *
 * ,-----------------------------------------------------------------------------------.
 * |      |      | PgUp | PgDn | Pscr |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Home |  End | Paus |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Ins  |  Del | Slck |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    KC_TRNS,  KC_TRNS,  KC_PGUP,  KC_PGDN,   KC_PSCR, _______, _______, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_HOME,  KC_END,    KC_PAUS, _______, _______, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_INS,   KC_DEL,    KC_SLCK, _______, _______, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, _______, _______, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS
)

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}