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
#include "pdl.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_wrapper( \
    KC_TAB,  _________________QWERTY_L1_________________,                                                                _________________QWERTY_R1_________________, KC_BSPC, \
    MY_SESC, _________________QWERTY_L2_________________,          KC_LALT, KC_LGUI,          FUNCTN, MY_AMNU,           _________________QWERTY_R2_________________, MY_SQUO, \
    MY_CBSL, _________________QWERTY_L3_________________, NAVIGN,  KC_BSPC, NUMBRS,           NUMBRS, MY_SSPC, NAVIGN,   _________________QWERTY_R3_________________, MY_CENT \
  ),

  [_PROXIM] = LAYOUT_wrapper( \
    KC_TAB,  _________________PROXIM_L1_________________,                                                                _________________PROXIM_R1_________________, KC_BSPC, \
    MY_SESC, _________________PROXIM_L2_________________,          KC_LALT, KC_LGUI,          FUNCTN, MY_AMNU,           _________________PROXIM_R2_________________, MY_SSCL, \
    MY_CBSL, _________________PROXIM_L3_________________, NAVIGN,  KC_BSPC, NUMBRS,           NUMBRS, MY_SSPC, NAVIGN,   _________________PROXIM_R3_________________, MY_CENT \
  ),

  [_NAVIGN] = LAYOUT_wrapper( \
    _______, _________________NAVIGN_L1_________________,                                                                _______, _______, _______, _______, _______, _______, \
    _______, _________________NAVIGN_L2_________________,          _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______, \
    _______, _________________NAVIGN_L3_________________, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  [_PUNCTN] = LAYOUT_wrapper( \
    _______, _______, _______, _______, _______, _______,                                                                _________________PUNCTN_R1_________________, _______, \
    _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______,          _________________PUNCTN_R2_________________, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _________________PUNCTN_R3_________________, _______  \
  ),

  [_NUMBRS] = LAYOUT_wrapper( \
    _______, _________________NUMBRS_L1_________________,                                                                _______, _______, _______, _______, _______, _______, \
    _______, _________________NUMBRS_L2_________________,           _______, _______,         _______, _______,          _______, _______, _______, _______, _______, _______, \
    _______, _________________NUMBRS_L3_________________,  _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),

  [_CODING] = LAYOUT_wrapper( \
    _______, _______, _______, _______, _______, _______,                                                                _________________CODING_R1_________________, _______, \
    _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______,          _________________CODING_R2_________________, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _________________CODING_R3_________________, _______  \
  ),

  [_FUNCTN] = LAYOUT_wrapper( \
    _______, _________________FUNCTN_L1_________________,                                                                _________________FUNCTN_L1_________________, MY_CAD, \
    _______, _________________FUNCTN_L2_________________,           _______, _______,         _______, _______,          _________________FUNCTN_L2_________________, KC_PSCR, \
    _______, _________________FUNCTN_L3_________________,  _______, _______, _______,         _______, _______, _______, _________________FUNCTN_L3_________________, _______  \
  )
};

/*  [_ADJUST] = LAYOUT_wrapper( \
 *    _______, _______, _______, _______, _______, _______,                                                                _______, _______, _______, _______, _______, _______, \
 *    _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______, \
 *    _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______  \
 *  )
 */


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
