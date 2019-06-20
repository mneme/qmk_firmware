#include <stdarg.h>
#include QMK_KEYBOARD_H
#include "led.h"
#include "action_layer.h"
#include "action_util.h"

/*
 * MAC SWEDISH
 */
#define KM_PLUS KC_MINS           // +
#define KM_ACUT KC_EQL            // ´
#define KM_AO	  KC_LBRC           // Å
#define KM_UMLA KC_RBRC           // ¨
#define KM_OE	  KC_SCLN           // Ö
#define KM_AE	  KC_QUOT           // Ä
#define KM_QUOT KC_NUHS           // '
#define KM_LABK KC_NUBS           // <
#define KM_MINS KC_SLSH           // -
#define KM_EXLM LSFT(KC_1)        // !
#define KM_DQT  LSFT(KC_2)        // "
#define KM_AT   RALT(KC_2)        // @
#define KM_HASH LSFT(KC_3)        // #
#define KM_EUR  LSFT(KC_4)        // €
#define KM_DLR  LALT(KC_4)        // $
#define KM_PERC LSFT(KC_5)        // %
#define KM_AMPR LSFT(KC_6)        // &
#define KM_SLSH LSFT(KC_7)        // /
#define KM_LPRN LSFT(KC_8)        // (
#define KM_RPRN LSFT(KC_9)        // )
#define KM_EQL  LSFT(KC_0)        // =
#define KM_UNDS LSFT(KM_MINS)     // _
#define KM_QUES LSFT(KM_PLUS)     // ?
#define KM_GRAV LSFT(KM_ACUT)     // `
#define KM_LCBR LSFT(LALT(KC_8))  // {
#define KM_RCBR LSFT(LALT(KC_9))  // }
#define KM_LBRC LALT(KC_8)        // [
#define KM_RBRC LALT(KC_9)        // ]
#define KM_RABK LSFT(KM_LABK)     // <
#define KM_COLN LSFT(KC_DOT)      // :
#define KM_SCLN LSFT(KC_COMM)     // :
#define KM_PIPE LALT(KC_7)        // |
#define KM_QUES LSFT(KM_PLUS)     // ?
#define KM_CIRC LSFT(KM_UMLA)     // ^
#define KM_ASTR LSFT(KM_QUOT)     // *
#define KM_TILD LALT(KM_UMLA)     // ~
#define KM_BSLS LSFT(LALT(KC_7))   //
#define KM_AO	 KC_LBRC         // Å
#define KM_UMLA KC_RBRC         // ¨
#define KM_OE	 KC_SCLN         // Ö
#define KM_AE	 KC_QUOT         // Ä

/*
 * WINDOWS SWEDISH
 */
#define KW_HALF KC_GRV          // 1/2
#define KW_PLUS KC_MINS         // +
#define KW_ACUT KC_EQL          // ´
#define KW_AO	 KC_LBRC         // Å
#define KW_UMLA KC_RBRC         // ¨
#define KW_OE	 KC_SCLN         // Ö
#define KW_AE	 KC_QUOT         // Ä
#define KW_QUOT KC_NUHS         // '
#define KW_LABK KC_NUBS         // <
#define KW_MINS KC_SLSH         // -
#define KW_EXLM LSFT(KC_1)      // !
#define KW_DQT  LSFT(KC_2)      // "
#define KW_AT   RALT(KC_2)      // @
#define KW_HASH LSFT(KC_3)      // #
#define KW_EUR  LSFT(KC_4)      // €
#define KW_DLR  RALT(KC_4)      // $
#define KW_PERC LSFT(KC_5)      // %
#define KW_AMPR LSFT(KC_6)      // &
#define KW_SLSH LSFT(KC_7)      // /
#define KW_LPRN LSFT(KC_8)      // (
#define KW_RPRN LSFT(KC_9)      // )
#define KW_EQL  LSFT(KC_0)      // =
#define KW_UNDS LSFT(KW_MINS)   // _
#define KW_QUES LSFT(KW_PLUS)   // ?
#define KW_GRAV LSFT(KW_ACUT)   // `
#define KW_LCBR RALT(KC_7)      // {
#define KW_RCBR RALT(KC_0)      // }
#define KW_LBRC RALT(KC_8)      // [
#define KW_RBRC RALT(KC_9)      // ]
#define KW_RABK LSFT(KW_LABK)   // <
#define KW_COLN LSFT(KC_DOT)    // :
#define KW_SCLN LSFT(KC_COMM)   // :
#define KW_PIPE RALT(KW_LABK)   // |
#define KW_QUES LSFT(KW_PLUS)   // ?
#define KW_CIRC LSFT(KW_UMLA)   // ^
#define KW_ASTR LSFT(KW_QUOT)   // *
#define KW_TILD RALT(KW_UMLA)   // ~
#define KW_BSLS RALT(KW_PLUS) //

// OSM MODS
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_RCTL OSM(MOD_RCTL)
#define OSM_RALT OSM(MOD_RALT)
#define OSM_RSFT OSM(MOD_RSFT)
#define OSM_RGUI OSM(MOD_RGUI)

#define KC_SUP LALT(LCTL(KC_LGUI))
#define KC_HAM LALT(LCTL(LGUI(KC_SPC)))
#define KC_HYP LSFT(LALT(LCTL(KC_LGUI))
#define KC_TML LCTL(KC_A)

#define TAP_ONCE(code)  \
  register_code (code); \
  unregister_code (code)

// Layers
enum {
  BASE = 0,
  NAV,
  SYM,
  WIN_BASE,
  WIN_NAV,
  WIN_SYM
};

//Macros
enum {
  KF_1 = SAFE_RANGE, // 1, F1
  KF_2, // ...
  KF_3,
  KF_4,
  KF_5,
  KF_6,
  KF_7,
  KF_8,
  KF_9,
  KF_10,
  KF_11,
  KF_12,
  KF_FU,
  KF_SH,
  KF_LF,
  KF_TF,
  KF_BASE,
  KF_WIN
};

// Tapdance
enum {
  TD_FUN = 0,
  TD_EQ
};

//State and timers
uint16_t kf_timers[12];

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KF_11,    KF_1,     KF_2,     KF_3,     KF_4,    KF_5,                       KF_6,    KF_7,     KF_8,     KF_9,     KF_10,    KF_12,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,                       KC_Y,    KC_U,     KC_I,     KC_O,     KC_P,     KM_AO,
    OSM_LCTL, KC_A,     KC_S,     KC_D,     KC_F,    KC_G,                       KC_H,    KC_J,     KC_K,     KC_L,     KM_OE,    KM_AE,
    OSM_LSFT, KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,                       KC_N,    KC_M,     KC_COMM,  KC_DOT,   KM_MINS,  OSM_LSFT,
    MO(NAV),  OSM_LCTL, OSM_LALT, OSM_LGUI, KC_TML,  KC_BSPC,  KC_DEL, KC_ENT,  KC_SPC,  OSL(SYM), OSM_RGUI, OSM_RALT, OSM_RCTL, KC_HAM
  ),

  [NAV] = LAYOUT(
    RESET,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KF_WIN,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                    KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_L,     KC_TRNS,                    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU
  ),

  [SYM] = LAYOUT(
    KC_TRNS,  KF_SH,    KF_FU,    KF_LF,    KF_TF,    TD(TD_EQ),                   TD(TD_FUN), KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KM_LABK,  KM_RABK,  KM_LCBR,  KM_RCBR,  KM_PLUS,                     KM_AT,      KM_DQT,   KM_QUOT,  KM_GRAV,  KM_SLSH,  KC_TRNS,
    KC_TRNS,  KM_EXLM,  KM_EQL,   KM_LPRN,  KM_RPRN,  KM_MINS,                     KM_UNDS,    KM_CIRC,  KM_DLR,   KM_AMPR,  KM_PIPE,  KC_TRNS,
    KC_TRNS,  KM_TILD,  KM_PERC,  KM_LBRC,  KM_RBRC,  KM_ASTR,                     KM_HASH,    KM_SCLN,  KM_COLN,  KM_QUES,  KM_BSLS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  ),

  [WIN_BASE] = LAYOUT(
    KF_11,       KF_1,     KF_2,     KF_3,     KF_4,    KF_5,                      KF_6,    KF_7,         KF_8,     KF_9,     KF_10,    KF_12,
    KC_TAB,      KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,                      KC_Y,    KC_U,         KC_I,     KC_O,     KC_P,     KM_AO,
    KC_LCTL,     KC_A,     KC_S,     KC_D,     KC_F,    KC_G,                      KC_H,    KC_J,         KC_K,     KC_L,     KM_OE,    KM_AE,
    KC_LSFT,     KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,                      KC_N,    KC_M,         KC_COMM,  KC_DOT,   KM_MINS,  KC_LSFT,
    MO(WIN_NAV), KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,  KC_BSPC,  KC_DEL, KC_ENT,  KC_SPC,  OSL(WIN_SYM), KC_RALT,  KC_RGUI,  KC_RCTL,  KC_HAM
  ),

  [WIN_NAV] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KF_BASE,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                    KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_LSFT,  KC_LCTL,  KC_LGUI,  KC_LALT,  KC_TRNS,                    KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU
  ),

  [WIN_SYM] =  LAYOUT(
    KC_TRNS,  KF_SH,    KF_FU,    KF_LF,    KF_TF,    KC_TRNS,                     KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KW_LABK,  KW_RABK,  KW_LCBR,  KW_RCBR,  KW_PLUS,                     KW_AT,      KW_DQT,   KW_QUOT,  KW_GRAV,  KW_SLSH,  KC_TRNS,
    KC_TRNS,  KW_EXLM,  KW_EQL,   KW_LPRN,  KW_RPRN,  KW_MINS,                     KW_UNDS,    KW_CIRC,  KW_DLR,   KW_AMPR,  KW_PIPE,  KC_TRNS,
    KC_TRNS,  KW_TILD,  KW_PERC,  KW_LBRC,  KW_RBRC,  KW_ASTR,                     KW_HASH,    KW_QUES,  KW_SCLN,  KW_COLN,  KW_BSLS,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
  )
};

static void m_tapn (uint8_t code, ...) {
  uint8_t kc = code;
  va_list ap;

  va_start(ap, code);
  do {
    TAP_ONCE(kc);
    wait_ms(10);
    kc = va_arg(ap, int);
  } while (kc != 0);
  va_end(ap);
}

static void m_handle_kf (keyrecord_t *record, uint16_t id) {
  uint16_t code = id - KF_1;

  if (record->event.pressed) {
    kf_timers[code] = timer_read ();
  } else {
    uint16_t kc_base;
    uint8_t long_press = (kf_timers[code] && timer_elapsed (kf_timers[code]) > TAPPING_TERM);

    kf_timers[code] = 0;

    switch(id){
      case KF_1 ... KF_10:
        if (long_press) {
          // Long press
          kc_base = KC_F1;
        } else {
          kc_base = KC_1;
        }
        code += kc_base;
        break;
      case KF_11:
        code = long_press ? KC_F11 : KC_ESC;
        break;
      case KF_12:
        code = long_press ? KC_F12 : KM_PLUS;
        break;
    }
    TAP_ONCE(code);
  }
}

// TAP DANCE SETTINGS
void dance_eq (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1: // ===
      register_code(KC_LSHIFT);
      m_tapn(KC_0, KC_0, KC_0, 0);
      unregister_code(KC_LSHIFT);
      break;
    case 2: // !==
      register_code(KC_LSHIFT);
      m_tapn(KC_1, KC_0, KC_0, 0);
      unregister_code(KC_LSHIFT);
      break;
    default:
      reset_tap_dance(state);
  }
}

void dance_fun (qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1: // =>
      register_code(KC_LSHIFT);
      m_tapn(KC_0, KM_LABK, 0);
      unregister_code(KC_LSHIFT);
      break;
    case 2: // () => {\n
      register_code(KC_LSHIFT);
      m_tapn(KC_8, KC_9, KC_SPC, KC_0, KM_LABK, KC_SPC, 0);
      unregister_code(KC_LSHIFT);
      register_code(KC_LSFT);
      register_code(KC_LALT);
      TAP_ONCE(KC_8);
      unregister_code(KC_LALT);
      unregister_code(KC_LSFT);
      TAP_ONCE(KC_ENT);
      break;
    default:
      reset_tap_dance(state);
  }
}

void m_unicode_begin(void) {
  register_code (KC_LALT);
  register_code (KC_LGUI);
  TAP_ONCE(KC_SPC);
  unregister_code (KC_LGUI);
  unregister_code (KC_LALT);
  unicode_input_start();
}

void m_unicode_finish(void) {
  unicode_input_finish();
  register_code (KC_LALT);
  register_code (KC_LGUI);
  TAP_ONCE(KC_SPC);
  unregister_code (KC_LGUI);
  unregister_code (KC_LALT);
}

static void m_tapu (uint32_t code, ...){
  uint32_t kc = code;
  va_list ap;

  m_unicode_begin();
  va_start(ap, code);
  do {
    register_hex(kc);
    wait_ms(10);
    kc = va_arg(ap, int);
  } while (kc != 0);
  va_end(ap);
  m_unicode_finish();
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_FUN] = ACTION_TAP_DANCE_FN (dance_fun),
  [TD_EQ] = ACTION_TAP_DANCE_FN (dance_eq)
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  switch (default_layer_state){
    case BASE:
      set_unicode_input_mode(UC_OSX);
      break;
    case WIN_BASE:
        set_unicode_input_mode(UC_WINC);
      break;
  }
};

//'m_send_unicode(' + '<SHRUGGIE GOES HERE>'.split('').map(c => '0x0' + String.prototype.charCodeAt.apply(c).toString(16)).join(' ') );'

// ¯\_(ツ)_/¯
void shrug(void) {
  m_tapu(0x0af, 0x05c, 0x05f, 0x028, 0x030c4, 0x029, 0x05f, 0x02f, 0x0af, 0);
}

//凸(ツ)凸
void fu(void) {
  m_tapu(0x051f8, 0x028, 0x030c4, 0x029, 0x051f8, 0);
}

// ( ͡° ͜ʖ ͡°)
void lenny(void){
  m_tapu(0x028, 0x020, 0x0361, 0x0b0, 0x020, 0x035c, 0x0296, 0x020, 0x0361, 0x0b0, 0x029, 0);
}

// (╯°□°）╯︵ ┻━┻)
void table(void){
  m_tapu(0x028, 0x0256f, 0x0b0, 0x025a1, 0x0b0, 0x0ff09, 0x0256f, 0x0fe35, 0x020, 0x0253b, 0x02501, 0x0253b, 0);
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) { };

// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool queue = true;
  switch (keycode) {
    case KF_BASE:
        set_single_persistent_default_layer(BASE);
        set_unicode_input_mode(UC_OSX);
        break;
    case KF_WIN:
        set_single_persistent_default_layer(WIN_BASE);
        set_unicode_input_mode(UC_WINC);
        break;
    case KF_1 ... KF_12:
        m_handle_kf(record, keycode);
        break;
    default:
        if (!record->event.pressed) {
          break;
        }
        switch (keycode){
        case KF_FU:
            fu();
            break;
        case KF_SH:
            shrug();
            break;
        case KF_LF:
            lenny();
            break;
        case KF_TF:
            table();
            break;
        }
  }
  return queue;
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{

  return MACRO_NONE;
};
