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
extern keymap_config_t keymap_config;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KEYMAP_wrapper( \
    KC_TAB,  _________________QWERTY_L1_________________, _________________QWERTY_R1_________________, KC_BSPC, \
    MY_SESC, _________________QWERTY_L2_________________, _________________QWERTY_R2_________________, MY_SQUO, \
    MY_CBSL, _________________QWERTY_L3_________________, _________________QWERTY_R3_________________, MY_CENT, \
    KC_LCTL, KC_LGUI, KC_LALT, NUMBRS,  NAVIGN, KC_SPC,   MY_SSPC, NUMBRS,  NAVIGN,  MY_AMNU, FUNCTN,  KC_ENT   \
  ),
  [_PROXIM] = KEYMAP_wrapper( \
    KC_TAB,  _________________PROXIM_L1_________________, _________________PROXIM_R1_________________, KC_BSPC, \
    MY_SESC, _________________PROXIM_L2_________________, _________________PROXIM_R2_________________, MY_SSCL, \
    MY_CBSL, _________________PROXIM_L3_________________, _________________PROXIM_R3_________________, MY_CENT, \
    KC_LCTL, KC_LGUI, KC_LALT, NUMBRS,  NAVIGN, KC_SPC,   MY_SSPC, NUMBRS,  NAVIGN,  MY_AMNU, FUNCTN,  KC_ENT   \
  ),
  [_NAVIGN] = KEYMAP_wrapper( \
    _______, _________________NAVIGN_L1_________________, _______, _______, _______, _______, _______, _______, \
    _______, _________________NAVIGN_L2_________________, _______, _______, _______, _______, _______, _______, \
    _______, _________________NAVIGN_L3_________________, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),
  [_PUNCTN] = KEYMAP_wrapper( \
    _______, _______, _______, _______, _______, _______, _________________PUNCTN_R1_________________, _______, \
    _______, _______, _______, _______, _______, _______, _________________PUNCTN_R2_________________, _______, \
    _______, _______, _______, _______, _______, _______, _________________PUNCTN_R3_________________, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),
  [_NUMBRS] = KEYMAP_wrapper( \
    _______, _________________NUMBRS_L1_________________, _______, _______, _______, _______, _______, _______, \
    _______, _________________NUMBRS_L2_________________, _______, _______, _______, _______, _______, _______, \
    _______, _________________NUMBRS_L3_________________, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),
  [_CODING] = KEYMAP_wrapper( \
    _______, _______, _______, _______, _______, _______, _________________CODING_R1_________________, _______, \
    _______, _______, _______, _______, _______, _______, _________________CODING_R2_________________, _______, \
    _______, _______, _______, _______, _______, _______, _________________CODING_R3_________________, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  ),
  [_FUNCTN] = KEYMAP_wrapper( \
    _______, _________________FUNCTN_L1_________________, _________________FUNCTN_R1_________________, MY_CAD,  \
    _______, _________________FUNCTN_L2_________________, _________________FUNCTN_R2_________________, KC_PSCR, \
    _______, _________________FUNCTN_L3_________________, _________________FUNCTN_R3_________________, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
  )
};
