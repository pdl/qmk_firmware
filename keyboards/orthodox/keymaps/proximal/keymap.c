/*
This is the keymap for the keyboard

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger

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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _PROXIM 2
#define _NUMBRS 4
#define _NAVIGN 5
#define _PUNCTN 6
#define _CODING 7
#define _FUNCTN 8
#define _LOWER  13
#define _RAISE  14
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  PROXIM,
  NUMBRS,
  NAVIGN,
  PUNCTN,
  CODING,
  FUNCTN
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define MY_SSPC  MT(MOD_RSFT, KC_SPC)
#define MY_SESC  MT(MOD_LSFT, KC_ESC)
#define MY_CBSL  MT(MOD_LCTL, KC_NUBS)
#define MY_SSCL  MT(MOD_RSFT, KC_SCLN)
#define MY_SQUO  MT(MOD_RSFT, KC_QUOT)
#define MY_CENT  MT(MOD_RCTL, KC_ENT)
#define MY_AMNU  MT(MOD_RALT, KC_APP)

#define MY_TILD  S(KC_NUHS)
#define MY_SEQL  MT(MOD_RALT, KC_PEQL)
#define MY_CMIN  MT(MOD_RALT, KC_MINS)
#define MY_ASLS  MT(MOD_RALT, KC_SLSH)

#define MY_UNDO  LCTL(KC_Z)
#define MY_CUT   LCTL(KC_X)
#define MY_COPY  LCTL(KC_C)
#define MY_PASTE LCTL(KC_V)

#define MY_AF4  LALT(KC_F4)
#define MY_CF4  LCTL(KC_F4)
#define MY_CF5  LCTL(KC_F5)
#define MY_CAD  LCTL(LALT(KC_DEL))

#define EITHER_SHIFT (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
    MY_SESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_LALT, KC_LGUI,          FUNCTN, MY_AMNU,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, MY_SQUO, \
    MY_CBSL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    NAVIGN,  KC_BSPC, NUMBRS,           NUMBRS, MY_SSPC, NAVIGN,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MY_CENT \
  ),

  [_PROXIM] = LAYOUT( \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_R,    KC_B,                                                                   KC_J,    KC_Y,    KC_O,    KC_U,    KC_QUOT, KC_BSPC, \
    MY_SESC, KC_A,    KC_S,    KC_D,    KC_T,    KC_G,             KC_LALT, KC_LGUI,          FUNCTN, MY_AMNU,           KC_P,    KC_N,    KC_E,    KC_I,       KC_L, MY_SSCL, \
    MY_CBSL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_K,    NAVIGN,  KC_BSPC, NUMBRS,           NUMBRS, MY_SSPC, NAVIGN,   KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_MINS, MY_CENT \
  ),

  [_NAVIGN] = LAYOUT( \
    _______, KC_DEL,  KC_PGUP, KC_UP,   KC_PGDN, KC_BSPC,                                                                _______, _______, _______, _______, _______, _______, \
    _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,          _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______, \
    _______, MY_UNDO, MY_CUT,  MY_COPY, MY_PASTE, KC_ENT, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  [_PUNCTN] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                                                                KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, _______, _______, \
    _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______,          KC_ASTR, MY_SEQL, MY_CMIN, KC_PLUS, MY_ASLS, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______  \
  ),

  [_NUMBRS] =  LAYOUT( \
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                                   _______, _______, _______, _______, _______, _______, \
    _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,             _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______, \
    _______, KC_UNDO, KC_MINS, KC_EQL,  KC_PDOT, KC_ENT,  _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  [_CODING] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                                                                KC_GRV,  KC_PERC, KC_DLR,  KC_AT,   _______, _______, \
    _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______,          KC_CIRC, KC_UNDS, MY_TILD, KC_AMPR, KC_NUHS, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, KC_LBRC, KC_RBRC, _______, _______, _______, _______  \
  ),

  [_FUNCTN] = LAYOUT( \
    _______, KC_ESC,  KC_F1,   KC_F2,   KC_F3,   MY_AF4,                                                                 KC_VOLU, KC_F10,  KC_F11,  KC_F12,  KC_INS,  MY_CAD, \
    _______, KC_APP,  KC_F4,   KC_F5,   KC_F6,   MY_CF5,           _______, _______,          _______, _______,          KC_VOLD, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, KC_PSCR, \
    _______, RESET,   KC_F7,   KC_F8,   KC_F9,   MY_CF4,  _______, _______, _______,          _______, _______, _______, KC_MUTE, KC_PAUS, QWERTY,  PROXIM,  DEBUG,   _______  \
  ),

  [_ADJUST] = LAYOUT( \
    _______, _______, _______, _______, _______, _______,                                                                _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  )


};

// todo: put update_punctn_layer here and then we can use LT and similar?
//uint32_t layer_state_set_user(uint32_t state) {
//    return update_punctn_coding_layer_state(state)
//}

uint32_t update_punctn_coding_layer_state(uint32_t state) {
  uint32_t maskEither = _NAVIGN | _NUMBRS;
  uint32_t maskBoth   = _NAVIGN & _NUMBRS;
  uint32_t maskPunctn = 1UL << _PUNCTN;
  uint32_t maskCoding = 1UL << _CODING;

  return (
    (state & maskEither) == maskEither
    ? (state & maskBoth) == maskBoth
      ? (state | maskPunctn) & ~maskCoding // both    => coding
      : (state & ~maskPunctn) | maskCoding // either  => punctn
    : (state & ~maskCoding) & ~maskPunctn  // neither => neither
  );
}


/*
 * update_punctn_layer
 *
 * If either the NAVIGN or NUMBRS layer is active, PUNCTN should be active; if both are active, CODING should be active.
 *
 * Call this whenever the following changes are made:
 *
 * - NAVIGN layer activater or deactivated
 * - NUMBRS layer activater or deactivated
 *
 */

void update_punctn_layer (void) {
  if (IS_LAYER_ON(_NAVIGN) || IS_LAYER_ON(_NUMBRS)) {
    if (IS_LAYER_ON(_NAVIGN) && IS_LAYER_ON(_NUMBRS)) {
      layer_on(_PUNCTN);
      layer_on(_CODING);
    } else {
      layer_off(_CODING);
      layer_on(_PUNCTN);
    }
  } else {
    layer_off(_CODING);
    layer_off(_PUNCTN);
  }
}

// unshifted
//
// regardless of current mods, send this character in an unshifted state

bool unshifted (uint16_t keycode, keyrecord_t *record) {
  uint8_t mods;

  if (record->event.pressed) {
    mods = keyboard_report->mods & EITHER_SHIFT;

    if (mods) {
      unregister_mods(mods);
      register_code(keycode);
      register_mods(mods);
    } else {
      register_code(keycode);
    }

    return false;
  } else {
    return true;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case PROXIM:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_PROXIM);
      }
      return false;
      break;
    case NAVIGN:
      if (record->event.pressed) {
        layer_on(_NAVIGN);
      } else {
        layer_off(_NAVIGN);
      }
      update_punctn_layer();
      return false;
      break;
    case NUMBRS:
      if (record->event.pressed) {
        layer_on(_NUMBRS);
      } else {
        layer_off(_NUMBRS);
      }
      update_punctn_layer();
      return false;
      break;
    case FUNCTN:
      if (record->event.pressed) {
        layer_on(_FUNCTN);
      } else {
        layer_off(_FUNCTN);
      }
      return false;
      break;
    // KC_LBRC, KC_NUHS, KC_GRV, KC_RBRC [&#`]
    // These four keys are unshifted in the UK layout and should be sent as such.
    case KC_LBRC:
      return unshifted(keycode, record);
    case KC_NUHS:
      return unshifted(keycode, record);
    case KC_GRV:
      return unshifted(keycode, record);
    case KC_RBRC:
      return unshifted(keycode, record);
  }
  return true;
}
