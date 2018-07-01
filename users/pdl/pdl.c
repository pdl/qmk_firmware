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


// todo: put update_punctn_layer here and then we can use LT and similar?
//uint32_t layer_state_set_user(uint32_t state) {
//    return update_punctn_coding_layer_state(state)
//}
/*
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
*/

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
__attribute__ ((weak))
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

__attribute__ ((weak))
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      return unshifted(KC_Q, record);
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case PROXIM:
      return unshifted(KC_P, record);
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
