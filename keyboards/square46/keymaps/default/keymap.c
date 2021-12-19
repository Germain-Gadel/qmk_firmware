/* Copyright 2021 Germain Gadel
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

enum layers {
    _QWERTY,
    _FROW,
    _SYMBOLS,
    _ARROWS,
    _MEDIA,
    _NAV
};

enum custom_keycodes {
    TD_Q_ESC
};

#define FN1 LT(_FROW, KC_ESC)
#define FN2 LT(_SYMBOLS, KC_TAB)
#define FN3 MO(_ARROWS)
#define FN4 LT(_MEDIA, KC_ENT)
#define SFT_Z LSFT_T(KC_Z)
#define CTL_X LCTL_T(KC_X)
#define LGUIT_X LGUI_T(KC_C)
#define ALT_V LALT_T(KC_V)
#define ALT_M RALT_T(KC_M)
#define GUI_COMM RGUI_T(KC_COMM)
#define CLT_DOT RCTL_T(KC_DOT)
#define SFT_SLH RSFT_T(KC_SLSH)
#define NAV_A LT(_NAV, KC_A)
#define Q_ESC TD(TD_Q_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------.        ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |        |   6  |   7  |   8  |   9  |   0  |
 * |----------------------------------|        |----------------------------------|
 * |   Q  |   W  |   E  |   R  |   T  |        |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |        |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |        |   N  |   M  |   ,  |   .  |   /  |
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               |  Fn1 |  Fn2 | Space|        | Bspc |  Fn3 |  Fn4 |
 *               `--------------------'        `--------------------'
 */

[_QWERTY] = LAYOUT(
    KC_1,   KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,     KC_9,     KC_0,
    Q_ESC,  KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,
    NAV_A,  KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,
    SFT_Z,  CTL_X,   LGUIT_X, ALT_V,  KC_B,    KC_N,    ALT_M,   GUI_COMM, CLT_DOT,  SFT_SLH,
                     FN1,     FN2,    KC_SPC,  KC_BSPC, FN3,     FN4
),

/* F row
 * ,----------------------------------.        ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |        |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |----------------------------------|        |----------------------------------|
 * |      |      |      |      |      |        |      |      |      |  F11 |  F12 |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      |      |      |      |        |      |      |      |      |      |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      |      |      |      |        |      |      |      |      |      |
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               |      |      |      |        |      |      |      |
 *               `--------------------'        `--------------------'
*/

[_FROW] = LAYOUT(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,     KC_F5,      KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_F11,    KC_F12,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
                        KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* Symbols
 * ,----------------------------------.        ,----------------------------------.
 * |   `  |      |      |      |      |        |      |      |      |      |      |
 * |----------------------------------|        |----------------------------------|
 * |      |      |   _  |   +  |      |        |      |      |      |      |      |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |   {  |   }  |   -  |   =  |      |        |      |      |      |      |      |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |   [  |   ]  |   (  |   )  |      |        |      |      |      |      |      |
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               |      |      |      |        |      |      |      |
 *               `--------------------'        `--------------------'
 */

[_SYMBOLS] = LAYOUT(
    KC_GRV,   KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_UNDS,  KC_PLUS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_LCBR,  KC_RCBR,  KC_MINUS, KC_EQUAL,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_LBRC,  KC_RBRC,  KC_LPRN,  KC_RPRN,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
                        KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* Arrows
 * ,----------------------------------.        ,----------------------------------.
 * |      |      |      |      |      |        |      |      |      |   {  |   }  |
 * |----------------------------------|        |----------------------------------|
 * |      |      |      |      |      |        |      |      |      |   [  |   ]  |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      |      |      |      |        |      |      |      |  Up  |   '  |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      |      |      |      |        |      |      | Left | Down | Right|
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               |      |      |      |        |      |      |      |
 *               `--------------------'        `--------------------'
 */

[_ARROWS] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LCBR,   KC_RCBR,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_LBRC,   KC_RBRC,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_UP,     KC_QUOT,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,   KC_RIGHT,
                        KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* Media
 * ,----------------------------------.        ,----------------------------------.
 * | Reset|      |      |      |      |        |      |      |      |      |      |
 * |----------------------------------|        |----------------------------------|
 * |      |      |      |      |      |        |      |      |      |      |      |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      |      |      |      |        |      |      |PTrack| Vol+ |NTrack|
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      |      |      |      |        |      |      | Prev | Vol- | Next |
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               |      |      |      |        | Play | Mute |      |
 *               `--------------------'        `--------------------'
 */

[_MEDIA] = LAYOUT(
    RESET,    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_MRWD,  KC_VOLU,   KC_MFFD,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_VOLD,   KC_MNXT,
                        KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_MPLY,  KC_MUTE,  KC_TRNS
),

/* Navigation
 * ,----------------------------------.        ,----------------------------------.
 * |      |      | PrtSc| ScrL | Pause|        |      |      |      |      |      |
 * |----------------------------------|        |----------------------------------|
 * |      |      | PgUp | PgDn |      |        |      |      |      |      |      |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      | Home |  End |      |        |      |      |      |      |      |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      | Ins  |  Del |      |        |      |      |      |      |      |
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               |      |      |      |        |      |      |      |
 *               `--------------------'        `--------------------'
 */

[_NAV] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_PSCR,  KC_SLCK,   KC_PAUS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_PGUP,  KC_PGDN,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_HOME,  KC_END,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_INS,   KC_DEL,    KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
                        KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS
)

};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};
