#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

#define _QWERTY 0
#define _PROXIM 2
#define _NUMBRS 4
#define _NAVIGN 5
#define _PUNCTN 6
#define _CODING 7
#define _FUNCTN 8

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

// Taken from drashna:
// Since our quirky block definitions are basically a list of comma separated
// arguments, we need a wrapper in order for these definitions to be
// expanded before being used as arguments to the LAYOUT_xxx macro.
#if (!defined(LAYOUT) && defined(KEYMAP))
#define LAYOUT KEYMAP
#endif
#define KEYMAP_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#define ___________________________________________  _______, _______, _______, _______, _______

#define _________________QWERTY_L1_________________  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________  KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________  KC_Z,    KC_X,     KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________PROXIM_L1_________________  KC_Q,    KC_W,    KC_F,    KC_R,    KC_B
#define _________________PROXIM_L2_________________  KC_A,    KC_S,    KC_D,    KC_T,    KC_G
#define _________________PROXIM_L3_________________  KC_Z,    KC_X,    KC_C,    KC_V,    KC_K

#define _________________PROXIM_R1_________________  KC_J,    KC_Y,    KC_O,    KC_U,    KC_QUOT
#define _________________PROXIM_R2_________________  KC_P,    KC_N,    KC_E,    KC_I,    KC_L
#define _________________PROXIM_R3_________________  KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________PUNCTN_R1_________________  KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, _______
#define _________________PUNCTN_R2_________________  KC_ASTR, MY_SEQL, MY_CMIN, KC_PLUS, MY_ASLS
#define _________________PUNCTN_R3_________________  KC_LCBR, KC_RCBR, _______, _______, _______

#define _________________CODING_R1_________________  KC_GRV,  KC_PERC, KC_DLR,  KC_AT,   _______
#define _________________CODING_R2_________________  KC_CIRC, KC_UNDS, MY_TILD, KC_AMPR, KC_NUHS
#define _________________CODING_R3_________________  KC_LBRC, KC_RBRC, _______, _______, _______

#define _________________NAVIGN_L1_________________  KC_DEL,  KC_PGUP, KC_UP,   KC_PGDN, KC_BSPC
#define _________________NAVIGN_L2_________________  KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END
#define _________________NAVIGN_L3_________________  MY_UNDO, MY_CUT,  MY_COPY, MY_PASTE, KC_ENT

#define _________________NUMBRS_L1_________________  KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMBRS_L2_________________  KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________NUMBRS_L3_________________  KC_UNDO, KC_MINS, KC_EQL,  KC_PDOT, KC_ENT

#define _________________FUNCTN_L1_________________  KC_ESC,  KC_F1,   KC_F2,   KC_F3,   MY_AF4
#define _________________FUNCTN_L2_________________  KC_APP,  KC_F4,   KC_F5,   KC_F6,   MY_CF5
#define _________________FUNCTN_L3_________________  RESET,   KC_F7,   KC_F8,   KC_F9,   MY_CF4

#define _________________FUNCTN_R1_________________  KC_VOLU, KC_F10,  KC_F11,  KC_F12,  KC_INS
#define _________________FUNCTN_R2_________________  KC_VOLD, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT
#define _________________FUNCTN_R3_________________  KC_MUTE, KC_PAUS, QWERTY,  PROXIM,  DEBUG

#endif
