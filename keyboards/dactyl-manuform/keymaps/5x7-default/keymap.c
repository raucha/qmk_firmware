#include "dactyl-manuform.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN   1

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define JP_AT KC_LBRACKET
#define JP_LBRACKET KC_RBRACKET
#define JP_RBRACKET KC_BSLASH
#define JP_HAT KC_EQL

enum custom_keycodes {
    YOROSIKU = SAFE_RANGE,
    OTUKARE,
    SHIGE
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case YOROSIKU:
                SEND_STRING("yorosikuonegaisimasu"); // this is our macro!
                return false;
            case OTUKARE:
                SEND_STRING("otukaresamadesu"); // this is our macro!
                return false;
            case SHIGE:
                SEND_STRING("shigekanedesu"); // this is our macro!
                return false;
        }
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP_5x7(
  // left hand
    KC_NO,  KC_GRV,     KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
    KC_NO,  KC_TAB,     KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,
    KC_NO,  KC_LSHIFT,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,
    KC_NO,  KC_LCTRL,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,
                                    KC_ESC, KC_LGUI,
                                                    KC_SPC,     KC_LSFT,
                                                    LT(_FN, KC_ENTER), KC_LCTRL,
                                                    KC_DEL,     KC_LALT,
        // right hand
    KC_6,        KC_7,      KC_8,   KC_9,   KC_0,   KC_MINS,    JP_HAT,
    KC_Y,        KC_U,      KC_I,   KC_O,   KC_P,   JP_AT,      JP_LBRACKET,
    KC_H,        KC_J,      KC_K,   KC_L,   KC_SCLN,KC_QUOT,    JP_RBRACKET,
    KC_N,        KC_M,      KC_COMM,KC_DOT, KC_SLSH,KC_RO,      KC_JYEN,
                            KC_PGUP, KC_PGDN,
    KC_LSHIFT,         KC_SPC,
    KC_RCTRL,       LT(_FN, KC_ENTER),
    KC_LALT,        KC_BSPC),
[_FN] = KEYMAP_5x7(
  // left hand
   KC_NO,   RESET,      KC_F1,  KC_F2,    KC_F3,    KC_F4,    KC_F5,
   KC_NO,   KC_TAB,     _______,KC_HOME,  KC_END,    KC_UP,   _______,
   KC_NO,   KC_LSHIFT,  _______,SHIGE,  KC_LEFT,  KC_DOWN, KC_RIGHT,
   KC_NO,   KC_LCTRL,   _______,_______,  _______,  _______,  _______,
                        _______,_______,
                                                    KC_SPC,     KC_LSFT,
                                                    LT(_FN, KC_ENTER), KC_LCTRL,
                                                    KC_DEL,     KC_LALT,
        // right hand
    KC_F6,    KC_F7,    KC_F8,    KC_F9,     KC_F10,  KC_F11,  KC_F12,
    YOROSIKU,  KC_HOME,  KC_UP,    OTUKARE,   _______,  _______,  _______,
    KC_LEFT,  KC_DOWN,  KC_UP,  KC_RIGHT, _______, _______,  _______,
    KC_CALC,  KC_MAIL,  KC_MYCM,  KC_WHOM,  _______,   _______,  RESET,
                        _______,  _______,
    KC_LSHIFT,         KC_SPC,
    KC_RCTRL,       LT(_FN, KC_ENTER),
    KC_LALT,        KC_BSPC),
};



void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
