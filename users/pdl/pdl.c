#include "pdl.h"

// unshifted
//
// regardless of current mods, send this character in an unshifted state

__attribute__ ((weak))
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

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  PROXIM,
  NUMBRS,
  NAVIGN,
  PUNCTN,
  CODING,
  FUNCTN,
  NEW_SAFE_RANGE
};
