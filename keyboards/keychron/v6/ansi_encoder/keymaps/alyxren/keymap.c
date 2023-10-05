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
  WIN_BASE,
  WIN_FN,
  MY_BASE,
  MY_FN,
  MY_JPN_BASE,
  MY_JPN_FN
};

enum unicode_names {
    HIRO, HINU, HIHU, HIA, HIU, HIE, HIO, HIYA, HIYU, HIYO, HIWA, HIHO, HIHE,
    // R4
    HITA, HITE, HII, HISU, HIKA, HIN, HINA, HINI, HIRA, HISE, HLCB, HRCB, HIMU,
    // R3
    HITI, HITO, HISI, HIHA, HIKI, HIKU, HIMA, HINO, HIRI, HIRE, HIKE,
    // R2
    HITU, HISA, HISO, HIHI, HIKO, HIMI, HIMO, HINE, HIRU, HIME
};
const uint32_t unicode_map[] PROGMEM = {
    // R5
    [HIRO] = 0x308D, // ろ
    [HINU] = 0x306C, // ぬ
    [HIHU] = 0x3075, // ふ
    [HIA]  = 0x3042, // あ
    [HIU]  = 0x3046, // う
    [HIE]  = 0x3048, // え
    [HIO]  = 0x304A, // お
    [HIYA] = 0x3084, // や
    [HIYU] = 0x3086, // ゆ
    [HIYO] = 0x3088, // よ
    [HIWA] = 0x308F, // わ
    [HIHO] = 0x307B, // ほ
    [HIHE] = 0x3078, // へ
    // R4
    [HITA] = 0x305F, // た
    [HITE] = 0x3066, // て
    [HII]  = 0x3044, // い
    [HISU] = 0x3059, // す
    [HIKA] = 0x304B, // か
    [HIN]  = 0x3093, // ん
    [HINA] = 0x306A, // な
    [HINI] = 0x306B, // に
    [HIRA] = 0x3089, // ら
    [HISE] = 0x305B, // せ
    [HLCB] = 0xff62, // ｢
    [HRCB] = 0xff63, // ｣
    [HIMU] = 0x3080, // む
    // R3
    [HITI] = 0x3061, // ち
    [HITO] = 0x3068, // と
    [HISI] = 0x3057, // し
    [HIHA] = 0x306F, // は
    [HIKI] = 0x304D, // き
    [HIKU] = 0x304F, // く
    [HIMA] = 0x307E, // ま
    [HINO] = 0x306E, // の
    [HIRI] = 0x308A, // り
    [HIRE] = 0x308C, // れ
    [HIKE] = 0x3051, // け
    // R2
    [HITU] = 0x3064, // つ
    [HISA] = 0x3055, // さ
    [HISO] = 0x305D, // そ
    [HIHI] = 0x3072, // ひ
    [HIKO] = 0x3053, // こ
    [HIMI] = 0x307F, // み
    [HIMO] = 0x3082, // も
    [HINE] = 0x306D, // ね
    [HIRU] = 0x308B, // る
    [HIME] = 0x3081, // め

};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define AR_LOCK LGUI(KC_L)
#define AR_CTLT CTL_T(KC_ESC)
#define AR_JPN  DF(MY_JPN_BASE)
#define AR_ENG  DF(MY_BASE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_MUTE,  KC_PSCR,  KC_NO,    RGB_MOD,  _______,  _______,  _______,  _______,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_APP,   KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [WIN_FN] = LAYOUT_ansi_109(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,  _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,            _______,  _______),

    [MY_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,    KC_MUTE,  KC_PSCR,  AR_LOCK,  RGB_MOD,  KC_F13,   KC_F14,   KC_F15,   KC_F16,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,    KC_BSPC,  KC_F17,   KC_HOME,  KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,   KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,              KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(MY_FN), KC_APP,    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MY_FN] = LAYOUT_ansi_109(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,  _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,                                _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                AR_JPN,                                 _______,  _______,  _______,    _______,  _______,  _______,  _______,  _______,            _______,  _______),

    [MY_JPN_BASE] = LAYOUT_ansi_109(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,        KC_F12,   KC_MUTE,   KC_PSCR,  AR_LOCK, RGB_MOD,  KC_F13,   KC_F14,   KC_F15,   KC_F16,
        UM(HIRO), UM(HINU), UM(HIHU), UM(HIA),  UM(HIU),  UM(HIE),  UM(HIO),  UM(HIYA), UM(HIYU), UM(HIYO), UM(HIWA), UM(HIHO),      UM(HIHE), KC_BSPC,   KC_F17,   KC_HOME, KC_PGUP,  KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,
        KC_TAB,   UM(HITA), UM(HITE), UM(HII),  UM(HISU), UM(HIKA), UM(HIN),  UM(HINA), UM(HINI), UM(HIRA), UM(HISE), UM(HLCB),      UM(HRCB), UM(HIMU),  KC_DEL,   KC_END,  KC_PGDN,  KC_P7,    KC_P8,    KC_P9,
        KC_LCTL,  UM(HITI), UM(HITO), UM(HISI), UM(HIHA), UM(HIKI), UM(HIKU), UM(HIMA), UM(HINO), UM(HIKI), UM(HIRE), UM(HIKE),                KC_ENT,                                 KC_P4,    KC_P5,    KC_P6,    KC_PPLS,
        KC_LSFT,            UM(HITU), UM(HISA), UM(HISO), UM(HIHI), UM(HIKO), UM(HIMI), UM(HIMO), UM(HINE), UM(HIRU), UM(HIME),                KC_RSFT,             KC_UP,             KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(MY_JPN_FN), KC_APP,   KC_RCTL,   KC_LEFT,  KC_DOWN, KC_RGHT,  KC_P0,              KC_PDOT,  KC_PENT),
    [MY_JPN_FN] = LAYOUT_ansi_109(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,       KC_VOLU,  RGB_TOG,  _______,  _______,  RGB_TOG,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,                 _______,                                _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,                 _______,            _______,            _______,  _______,  _______,
        _______,  _______,  _______,                                AR_ENG,                                 _______,  _______,       _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [WIN_BASE]    = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]      = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [MY_BASE]     = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MY_FN]       = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [MY_JPN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MY_JPN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE

void matrix_init_user(void) {
    set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
}
