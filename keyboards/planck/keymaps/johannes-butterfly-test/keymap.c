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
#define GAMING 4


#define MOUSEKEY_DELAY             200
#define MOUSEKEY_INTERVAL          40
#define MOUSEKEY_MAX_SPEED         7
#define MOUSEKEY_TIME_TO_MAX       20
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | alt  |play/p| super|shift | Space|Raise | lower|  alt | altgr|      |fn    |
 * `-----------------------------------------------------------------------------------'
 */
[QWERTY] = {
  {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,       KC_P},
  {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN},
  {MT(MOD_LSFT, KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  MT(MOD_RSFT, KC_SLSH)},
  {MT(MOD_LCTL, KC_ESC), KC_TAB, MOD_LALT, KC_LGUI, LT(FUNCTION, KC_SPC), KC_BTN1, KC_BTN2, MO(RAISE), MO(LOWER), MT(MOD_RALT, KC_QUOT), KC_BSPC,   MT(MOD_RCTL, KC_ENT)}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  {   |  }   |  +   |      |      | Å    |  Ä   |  Ö   |   _  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   \  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[LOWER] = {
  {KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,   _______,   _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN},
  {S(KC_GRV), KC_LCBR,   KC_RCBR,   KC_PLUS,   _______, _______,   _______, _______, RALT(KC_W), RALT(KC_Q), RALT(KC_P), KC_UNDS},
  {_______, _______,   _______,   _______,  _______,  _______,  _______,  _______,_______, _______,_______, KC_PIPE},
  {_______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |  [   |  ]   |  =   |      |  left|  down|  up  | right|   -  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   |  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[RAISE] = {
  {  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  _______,  _______,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0},
  {  KC_GRV,   KC_LBRC,   KC_RBRC,   KC_EQL,   _______, _______,  _______,   KC_LEFT,   KC_DOWN, KC_UP,  KC_RIGHT, KC_MINS},
  {_______,   _______,   _______,   _______,  _______,  _______,  _______, _______,  _______, _______, _______, KC_BSLS},
  {_______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Fn
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  |  F11 |  F12 '
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      | prev | vol.d| vo.up| next |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | mute |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      | CAPS |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[FUNCTION] = {
  {KC_F1,  KC_F2,    KC_F3,    KC_F4, _______,  _______, _______,  _______, _______,  RGB_M_P, RGB_M_R,  RGB_M_SW   },
  {KC_F5,    KC_F6,    KC_F7,    KC_F8,   _______,  _______, _______,  KC_MS_LEFT,  KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, _______},
  {    KC_F9,    KC_F10,    KC_F11,    KC_F12, _______, _______, _______, KC_MS_WH_LEFT,  KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, TO(GAMING)},
  {RGB_TOG, RGB_VAI,  RGB_VAD,   _______,  _______,   _______,   _______,   KC_MS_BTN3, RGB_SAI,  RGB_SAD, RGB_HUI, RGB_HUD}
},

[GAMING] = {
  {  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,  _______,  _______,    KC_6,   KC_7,    KC_8,    KC_9,    KC_0},
  {KC_T, KC_Q,    KC_W,    KC_E,    KC_R,    XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,       KC_P},
  {KC_LSFT,   KC_A, KC_S,    KC_D,    KC_F,     XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    TO(QWERTY)},
  {KC_LCTL, KC_TAB, MOD_LALT, KC_LGUI, KC_SPC, KC_BTN1, KC_BTN2, MO(RAISE), MO(LOWER), MT(MOD_RALT, KC_QUOT), KC_BSPC,   MT(MOD_RCTL, KC_ENT)}
},

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}