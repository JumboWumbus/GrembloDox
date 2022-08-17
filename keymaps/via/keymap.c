#include QMK_KEYBOARD_H
#include "features/select_word.h"
#include <transactions.h>

enum Layer_name {
    HOME,
    NUMBER,
    SYMBOL,
    MOUSE,
    TXTEDI,
    RGBee

};


enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  EQ3X,
  SLWRD = SAFE_RANGE,
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_select_word(keycode, record, SLWRD)) { return false; }
  switch (keycode) {
    case UPDIR:  // Types ../ to go up a directory on the shell.
      if (record->event.pressed) {
        SEND_STRING("../");
      }
      break;

    case EQ3X:  // Types triple equal ===
      if (record->event.pressed) {
        SEND_STRING("===");
      }
      break;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  TL4   |      |      |      |      |      |      |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   E  |   R  |   T  |HYPER |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | "      |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| TAB  |           | Meh  |------+------+------+------+------+--------|
 * | TL3    | Z/L3 | X/L4 |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      | ESC  |                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | lsApp  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
	LAYOUT(
        // left hand
        TO(5)  , KC_NO            ,  KC_NO           , KC_NO , KC_NO , KC_NO , KC_NO,
        KC_NO  , KC_Q             ,  KC_W            , KC_E  , KC_R  , KC_T  , ALL_T(KC_NO),
        KC_DQUO, MT(MOD_LALT,KC_A), MT(MOD_LCTL,KC_S), KC_D  , KC_F  , KC_G  ,
        TG(3)  , LT(3, KC_Z)      , KC_X       , KC_C  , LT(4,KC_V)  , KC_B  , KC_TAB,
        KC_NO  , KC_NO            , KC_NO            , KC_NO , KC_ESC,
                                               MO(1) , KC_LGUI,
                                                                            KC_HOME,
                                               MO(2), MT(MOD_LSFT, KC_SPC), KC_ENT,
        // right hand
        KC_NO,     KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,           KC_NO,
        KC_NO,       KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             KC_NO,
                     KC_H,   KC_J,  KC_K,   MT(MOD_RCTL,KC_L),   MT(MOD_RALT,KC_SCLN),   KC_QUOT,
        MEH_T(KC_NO),KC_N,   KC_M,  KC_COMM, LT(4,KC_DOT), LT(3, KC_SLSH),   KC_RSFT,
                             KC_NO, KC_NO,  TO(6),  TO(7),          TO(1),
        KC_CAPS,        MO(1),
        KC_END,
        KC_ENT,MT(MOD_LSFT, KC_SPC), MO(2)
    ),
/* Keymap 1: NUMBER AND FUNCTIONS
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F11 |  F12 |  F13 |  F14 |  F15 |      |           |      |  F16 |  F17 |  F18 |  F19 | F20  |        |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   F1 |   F2 |   F3 |   F4 |   F5 |      |           |      |   F6 |   F7 |   F8 |   F9 |  F10 |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |  10  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
	LAYOUT(
       // left hand
       KC_NO ,  KC_F11,    KC_F12,    KC_F13,    KC_F14,     KC_F15,    KC_NO ,
       KC_NO ,  KC_F1,  KC_F2,    KC_F3,  KC_F4,   KC_F5,  KC_NO ,
       KC_NO ,  KC_1,  KC_2,   KC_3,  KC_4,   KC_5,
       KC_NO ,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,  KC_NO ,
       KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,  KC_NO ,
                                                          KC_NO,KC_NO ,
                                                                  KC_NO ,
                                                  KC_NO,KC_NO,KC_NO ,
       // right hand
       KC_NO , KC_F16,   KC_F17,  KC_F18,   KC_F19,   KC_F20,  KC_NO,
       KC_NO , KC_F6,   KC_F7,   KC_F8,    KC_F9,    KC_F10,  KC_NO,
                KC_6, KC_7,   KC_8,    KC_9,    KC_0, KC_NO ,
       KC_NO , KC_NO, KC_NO,   KC_NO,    KC_NO,    KC_NO, KC_NO ,
                         KC_NO ,KC_NO,  KC_NO,    KC_NO,  KC_NO ,
       KC_NO, KC_NO ,
       KC_NO ,
       KC_NO , KC_NO, KC_NO
    ),
/* Keymap 2: SYMBOLS
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
	LAYOUT(
       // left hand
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO,
       KC_NO  , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_NO,
       KC_TILD, KC_UNDS, KC_BSPC, KC_LPRN, KC_RPRN, KC_LCBR,
       KC_NO  , KC_BSLS, KC_NO  , KC_LBRC, KC_RBRC, KC_RCBR, KC_NO,
       KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
       KC_NO  ,  KC_AMPR, EQ3X  , UPDIR  , KC_NO  , KC_PIPE, KC_NO  ,
                 KC_CIRC, KC_PLUS, KC_PMNS, KC_EQL , KC_COLN, KC_GRV ,
       KC_NO  ,  KC_NO  , KC_ASTR, KC_LABK, KC_RABK, KC_SLSH, KC_NO  ,
                          KC_VOLD, KC_VOLU, KC_NO  , KC_NO  , KC_NO  ,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_NO
    ),
/* Keymap 3: MOUSE AND ARROWS
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
	LAYOUT(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN4, KC_MS_U, KC_BTN5, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,
       TG(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_BTN3, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS,S(KC_TAB),KC_TAB, KC_ENT, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_UP   ,KC_DOWN,KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_WH_D, KC_WH_U, KC_TRNS, KC_TRNS, TO(0) ,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS  , KC_LCTL,
       KC_TRNS,
       KC_MEH , KC_LSFT, KC_LALT
    ),

/*  KEYMAP 4: TXT NAV

 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | PGUP | PGDWN| HOME | END  | DELT |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| LEFT |  UP  | DOWN | RGHT | BKSP |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |INSRT |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |PRNT S|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
*/
LAYOUT(
// left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_PGUP, KC_PGDN, KC_HOME, KC_END, KC_DEL, KC_TRNS,
                 KC_LEFT, KC_UP  , KC_DOWN, KC_RGHT, KC_BSPC, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, SLWRD, KC_INS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS,
       KC_TRNS  , KC_TRNS,
       KC_TRNS,
       KC_TRNS , KC_TRNS, KC_TRNS
),

/*  Keymap 5: RGB AND AUDIO SETTINGS

 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
*/
    LAYOUT(
       // left hand
       TO(0)  , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, RGB_TOG, RGB_MOD,RGB_HUI,  RGB_SAI, RGB_VAI, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_LSFT, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS,S(KC_TAB),KC_TAB, KC_ENT, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_UP   ,KC_DOWN,KC_RGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TO(0) ,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS  , KC_LCTL,
       KC_TRNS,
       KC_MEH , KC_LSFT, KC_LALT
    ),


    
};
