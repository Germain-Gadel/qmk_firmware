// Copyright 2022 Germain_Gadel (@Germain_Gadel)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _COLEMAK,
    _NUM,
    _SYM,
    _ARROWS,
    _MEDIA,
    _NAV
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    INFO,
    CLEAR_O
};

enum {
    TD_Q_ESC
};

#define FN1 LT(_SYM, KC_ESC)
#define FN2 LT(_NUM, KC_TAB)
#define FN3 LT(_ARROWS, KC_ENT)
#define FN4_0 LT(_MEDIA, KC_MUTE)
#define FN4_1 LT(_MEDIA, KC_N)
#define FN4_2 LT(_MEDIA, KC_K)
#define SFT_Z LSFT_T(KC_Z)
#define SFT_BC LSFT_T(KC_LBRC)
#define CTL_X LCTL_T(KC_X)
#define CTL_BC LCTL_T(KC_RBRC)
#define LGUIT_C LGUI_T(KC_C)
#define LGUIT_D LGUI_T(KC_D)
#define ALT_V LALT_T(KC_V)
#define ALT_M RALT_T(KC_M)
#define ALT_D RALT_T(KC_D)
#define ALT_H RALT_T(KC_H)
#define ALT_F12 RALT_T(KC_F12)
#define GUI_COMM RGUI_T(KC_COMM)
#define CLT_DOT RCTL_T(KC_DOT)
#define SFT_SLH RSFT_T(KC_SLSH)
#define NAV_A LT(_NAV, KC_A)
#define Q_ESC TD(TD_Q_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,----------------------------------.        ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |        |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |        |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |        |   N  |   M  |   ,  |   .  |   /  |
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               |  Fn1 |  Fn2 | Space|        | Bspc |  Fn3 |  Fn4 |
 *               `--------------------'        `--------------------'
 */

[_QWERTY] = LAYOUT_3X5(
    Q_ESC,  KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,
    NAV_A,  KC_S,    KC_D,    KC_F,   KC_G,    KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,
    SFT_Z,  CTL_X,   LGUIT_C, ALT_V,  KC_B,    FN4_1,   ALT_M,   GUI_COMM, CLT_DOT,  SFT_SLH,
                     FN1,     FN2,    KC_SPC,  KC_BSPC, FN3,     FN4_0
),

/*
 * ,----------------------------------.        ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   B  |        |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   G  |        |   M  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |   Z  |   X  |   C  |   D  |   V  |        |   K  |   H  |   ,  |   .  |   /  |
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               |  Fn1 |  Fn2 | Space|        | Bspc |  Fn3 |  Fn4 |
 *               `--------------------'        `--------------------'
 */

[_COLEMAK] = LAYOUT_3X5(
    Q_ESC,   KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,     KC_Y,    KC_SCLN,
    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,     KC_I,    KC_O,
    SFT_Z,   CTL_X,   LGUIT_C, ALT_D,   KC_V,    FN4_2,   ALT_H,   GUI_COMM, CLT_DOT, SFT_SLH,
                      FN1,     FN2,     KC_SPC,  KC_BSPC, FN3,     FN4_0
),

/* Numbers
 * ,----------------------------------.        ,----------------------------------.
 * |   0  |   7  |   8  |   9  |      |        |  F1  |  F2  |  F3  |  F4  |  F5  |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |   4  |   5  |   6  |   =  |        |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |   1  |   2  |   3  |   -  |        |  F11 | AF12 |      |      |      |
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               |   .  |      |      |        |      |      |      |
 *               `--------------------'        `--------------------'
*/

[_NUM] = LAYOUT_3X5(
    KC_0,     KC_7,  KC_8,  KC_9,   KC_TRNS,    KC_F1,  KC_F2,   KC_F3,  KC_F4,   KC_F5,
    KC_TRNS,  KC_4,  KC_5,  KC_6,   KC_EQUAL,   KC_F6,  KC_F7,   KC_F8,  KC_F9,   KC_F10,
    KC_TRNS,  KC_1,  KC_2,  KC_3,   KC_MINUS,   KC_F11, ALT_F12, KC_TRNS, KC_TRNS, KC_TRNS,
                     KC_PDOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* Symbols
 * ,----------------------------------.        ,----------------------------------.
 * |   `  |      |   _  |   +  |      |        |      |      |      |      |      |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |   {  |   }  |   -  |   =  |      |        |      |      |      |      |      |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |   [  |   ]  |   (  |   )  |      |        |      |      |      |      |      |
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               |      |      |      |        |      |      |      |
 *               `--------------------'        `--------------------'
 */

[_SYM] = LAYOUT_3X5(
    KC_GRV,   KC_TRNS,  KC_UNDS,  KC_PLUS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_LCBR,  KC_RCBR,  KC_MINUS, KC_EQUAL,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    SFT_BC,   CTL_BC,   KC_LPRN,  KC_RPRN,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
                        KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* Arrows
 * ,----------------------------------.        ,----------------------------------.
 * |      |      |      |      |      |        |      |   {  |   }  |   [  |   ]  |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      |      |      |      |        |      |      |      |  Up  |   '  |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      |      |      |      |        |      |      | Left | Down | Right|
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               |      |      |      |        |      |      |      |
 *               `--------------------'        `--------------------'
 */

[_ARROWS] = LAYOUT_3X5(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_LCBR,   KC_RCBR, KC_LBRC,   KC_RBRC,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_UP,     KC_QUOT,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN,   KC_RIGHT,
                        KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS
),

/* Media
 * ,----------------------------------.        ,----------------------------------.
 * |QWERTY|      |      | RESET|      |        |      |      |      |      |      |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      |      |      |      |        |      |      |PTrack| Vol+ |NTrack|
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      |COLEMK|      |      |        |      |      | Prev | Vol- | Next |
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               | INFO |CLEARO|      |        | Play | Mute |      |
 *               `--------------------'        `--------------------'
 */

[_MEDIA] = LAYOUT_3X5(
    QWERTY,   KC_TRNS,  KC_TRNS,  RESET,     KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_MRWD,  KC_VOLU,   KC_MFFD,
    KC_TRNS,  KC_TRNS,  COLEMAK,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_VOLD,   KC_MNXT,
                        INFO,     CLEAR_O,   KC_TRNS,    KC_MPLY,  KC_MUTE,  KC_TRNS
),

/* Navigation
 * ,----------------------------------.        ,----------------------------------.
 * |      |      | PgUp | PgDn | Pscr |        |      |      |      |      |      |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      | Home |  End | Paus |        |      |      |      |      |      |
 * |------+------+------+------+------|        |------+------+------+------+------|
 * |      |      | Ins  |  Del | Slck |        |      |      |      |      |      |
 * `-------------+------+------+------|        |------+------+------+-------------'
 *               |      |      |      |        |      |      |      |
 *               `--------------------'        `--------------------'
 */

[_NAV] = LAYOUT_3X5(
    KC_TRNS,  KC_TRNS,  KC_PGUP,  KC_PGDN,   KC_PSCR,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_HOME,  KC_END,    KC_PAUS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_INS,   KC_DEL,    KC_SLCK,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS,
                        KC_TRNS,  KC_TRNS,   KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS
)

};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_180;
    } else if (!is_keyboard_master()) {
        return rotation;
    }
    return rotation;
}

#    define KEYLOG_LEN 20
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("QWERTY"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("COLEMACK DH"), false);
            break;
    }
}

void render_layer_state(void) {
    oled_write_P(PSTR("SYM"), layer_state_is(_SYM));
    oled_write_char(' ', false);
    oled_write_P(PSTR("NUM"), layer_state_is(_NUM));
    oled_write_char(' ', false);
    oled_write_P(PSTR("ARR"), layer_state_is(_ARROWS));
    oled_write_char(' ', false);
    oled_write_P(PSTR("MED"), layer_state_is(_MEDIA));
    oled_write_char(' ', false);
    oled_write_ln_P(PSTR("NAV"), layer_state_is(_NAV));
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("SFT"), (modifiers & MOD_MASK_SHIFT));
    oled_write_char(' ', false);
    oled_write_P(PSTR("CTL"), (modifiers & MOD_MASK_CTRL));
    oled_write_char(' ', false);
    oled_write_P(PSTR("GUI"), (modifiers & MOD_MASK_GUI));
    oled_write_char(' ', false);
    oled_write_ln_P(PSTR("ALT"), (modifiers & MOD_MASK_ALT));
}
/*
static void oled_render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,  0,255,255,255,131,  3,  3,  3,  7, 31, 63,127,243,227,195,131,  3,  3,  3,  3,  3,  7, 63,255,251,227,  3,  3,255,255,255,  0,  0,255,255,255,  7, 15, 30, 60,120,240,240,224,192,129,  3,  7, 15, 28,120,240,224,192,128,  0,  3, 31, 63,252,255,255,255,  0,
        0,255,255,255,112,224,224,192,128,128,  0,  1,  3,  7, 15, 30, 30, 60,120,240,225,195,135,143, 62, 60,240,225,255,255,255,  0,  0, 15, 31, 31, 28, 28, 28, 29, 29, 31, 31, 31, 30, 30, 28, 28, 28, 28, 28, 28, 28, 29, 31, 31, 31, 30, 28, 29, 31, 31, 15,  0,
    };
    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}
*/
static void render_logo(void) {
    static const char PROGMEM my_logo[] = {
        // 'New Project', 128x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xc0, 0x0c, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xc0, 0x18, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x80, 0x38, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x70, 0x00, 0x00, 0x40, 0x40, 0x80, 0x03, 0x00, 0x30, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x38, 0x00, 0x00, 0xe0, 0xe1, 0xc0, 0x07, 0x00, 0x70, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x38, 0x00, 0x00, 0xe0, 0xe1, 0xc0, 0x0e, 0x00, 0x60, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x38, 0x00, 0x00, 0xe0, 0x01, 0xc0, 0x0e, 0x00, 0xe0, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x18, 0x00, 0x00, 0xe0, 0x01, 0xc0, 0x1c, 0x00, 0xc0, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x38, 0x04, 0x00, 0xe0, 0x01, 0xc0, 0x18, 0x01, 0xfc, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x38, 0x3f, 0x83, 0xfc, 0xe7, 0xf8, 0x3f, 0x01, 0xff, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x70, 0x7f, 0xe3, 0xfc, 0xe7, 0xf8, 0x3f, 0x83, 0xe7, 0x80, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0xc1, 0xf0, 0xe0, 0xe0, 0xe0, 0xe1, 0xc0, 0x03, 0xc3, 0x81, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0xff, 0xe1, 0xc0, 0x70, 0xe0, 0xe1, 0xc0, 0x01, 0xc7, 0x00, 0xe0, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0xff, 0x81, 0xc0, 0x30, 0xe0, 0xe1, 0xc0, 0x00, 0xe7, 0x00, 0xe0, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x01, 0xff, 0xf8, 0xe0, 0xe1, 0xc0, 0x00, 0xe6, 0x00, 0x60, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x01, 0xff, 0xf8, 0xe0, 0xe1, 0xc0, 0x00, 0xe6, 0x00, 0x60, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x01, 0xc0, 0x00, 0xe0, 0xe1, 0xc0, 0x00, 0xe6, 0x00, 0xe0, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x01, 0xc0, 0x00, 0xe0, 0xe1, 0xc0, 0x00, 0xe7, 0x00, 0xe0, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x00, 0xc0, 0x70, 0xe0, 0xe1, 0xc0, 0x01, 0xc3, 0x81, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x00, 0xf0, 0xe0, 0xe0, 0xe1, 0xc0, 0x07, 0xc3, 0xc3, 0xc0, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x00, 0x7f, 0xe0, 0xe0, 0xe1, 0xc3, 0xff, 0x81, 0xff, 0x80, 0x00, 0x00, 
        0x00, 0x00, 0x01, 0x80, 0x00, 0x3f, 0x80, 0xe0, 0xe1, 0xc3, 0xfe, 0x00, 0x7e, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(my_logo, sizeof(my_logo));
}

void render_status_main(void) {
    render_default_layer_state();
    render_layer_state();
    render_mod_status(get_mods());
    render_keylogger_status();
    oled_write_ln_P(PSTR(" "), false);
    //oled_render_logo();
}

bool oled_task_user(void) {
    update_log();
    if (is_keyboard_master()) {
        render_status_main();
    } else {
        render_logo();
    }
    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_0);
        } else {
            tap_code(KC_1);
        }
    } else if (index == 1) {
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                if (clockwise) {
                    tap_code(KC_WH_D);
                    tap_code(KC_WH_D);
                    tap_code(KC_WH_D);
                    tap_code(KC_WH_D);
                    tap_code(KC_WH_D);
                    tap_code(KC_WH_D);
                } else {
                    tap_code(KC_WH_U);
                    tap_code(KC_WH_U);
                    tap_code(KC_WH_U);
                    tap_code(KC_WH_U);
                    tap_code(KC_WH_U);
                    tap_code(KC_WH_U);
                }
                break;
            case _ARROWS:
                if (clockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
                break;
            case _NUM:
                if (clockwise) {
                    tap_code(KC_WH_L);
                } else {
                    tap_code(KC_WH_R);
                }
                break;
            default:
                // Nothing
                break;
        }
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode);
    }
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
    }
    return true;
}
