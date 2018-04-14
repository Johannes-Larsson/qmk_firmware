#include "planck.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define QWERTY 0
#define LOWER 1
#define RAISE 2
#define FUNCTION 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |esc/fn|tab   | super| ctrl | sp/sh|Raise | lower|  alt | backs|ent/fn|      |
 * `-----------------------------------------------------------------------------------'
 */
[QWERTY] = {
  {TERM_ON,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______},
  {TERM_OFF,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______},
  {_______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______ },
  {_______, LT(FUNCTION, KC_ESC), KC_TAB, KC_LGUI, KC_LCTRL, MT(KC_LSHIFT, KC_SPC),  MO(RAISE),   MO(LOWER),   KC_LALT, KC_BSPACE, LT(FUNCTION, KC_ENT), _______}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   ~  |  {   |  }   |  +   |   "  |      | Å    |  Ä   |  Ö   |   _  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[LOWER] = {
  {_______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______},
  {_______, KC_TILD,   KC_LCBR,   KC_RCBR,   KC_PLUS,   KC_DQT,   _______,   RALT(KC_W), RALT(KC_Q), RALT(KC_P), KC_UNDS, _______},
  {_______, _______,   _______,   _______,   _______,  _______,  _______,_______, _______,_______, KC_BSLS, _______},
  {_______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   `  |  [   |  ]   |  =   |   '  |  left|  down|  up  | right|   -  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   |  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[RAISE] = {
  {_______,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______},
  {_______,  _______,   KC_LBRC,   KC_RBRC,   KC_EQL,   KC_QUOT,   KC_LEFT,   KC_DOWN, KC_UP,  KC_RIGHT, KC_MINS, _______},
  {_______, _______,   _______,   _______,   _______,  _______,  _______,  _______, _______, _______, KC_PIPE, _______},
  {_______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Fn
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      | prev | vol.d| vo.up| next |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      | mute |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | CAPS |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[FUNCTION] = {
  {_______, KC_F1,  KC_F2,    KC_F3,    KC_F4,    _______,   _______,   _______, _______,  _______, _______, _______},
  {_______, KC_F5,  KC_F6,    KC_F7,    KC_F8,   _______,  KC_MEDIA_PREV_TRACK,  KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, _______, _______},
  {_______, KC_F9,  KC_F10,   KC_F11,   KC_F12, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, _______, _______, _______, _______},
  {_______,  _______,   _______,   _______,   KC_CAPS,   _______,   _______,   _______, _______,  _______, _______, _______}
},

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  return MACRO_NONE;
};
