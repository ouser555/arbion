#include QMK_KEYBOARD_H
#include "analog.h"

enum layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum jmodes {
    _MOUSE = 0,
    _SCROLL,
    _JOYS,
    _WASD,
};

//uint8_t jMode = _MOUSE;
uint8_t jMode = _WASD;

void joysitck_mode_INC(void) {
  if(jMode == _WASD) {
    jMode = _MOUSE;
  }else{
    jMode++;
  }
}
void joysitck_mode_DEC(void) {
  if(jMode == _MOUSE) {
    jMode = _WASD;
  }else{
    jMode--;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-----------------------.
 * |   1   |   2   |   3   |
 * |-------+-------+-------|
 * |   4   | 5/ENT |   6   | Dbl Tap 5 for Enter
 * |-------+-------+-------|
 * |  7/0  |   8   | 9/FN  | 7/0 = Dbl Tap 7 for 0  -  9/FN = Hold 9 for FN
 * `-----------------------'
 */
[_QWERTY] = LAYOUT(
  KC_1,       KC_2,      KC_3,
  KC_4,       KC_5,      KC_6,
  KC_7,       KC_8,      LT(1, KC_9)
),

/* LAYER 1
 * ,-----------------------.
 * |  ESC  |   +   |   -   |
 * |-------+-------+-------|
 * |  BSPC |   *   |   /   |
 * |-------+-------+-------|
 * |  00   |   .   |       |
 * `-----------------------'
 */
[_LOWER] = LAYOUT(
  KC_ESC,   KC_PLUS, KC_MINS,
  KC_ENTER, KC_ASTR, KC_SLSH,
  KC_0,     KC_DOT,  KC_TRNS
),

/* LAYER 1
 * ,-----------------------.
 * |  ESC  |   +   |   -   |
 * |-------+-------+-------|
 * |  BSPC |   *   |   /   |
 * |-------+-------+-------|
 * |  00   |   .   |       |
 * `-----------------------'
 */
[_RAISE] = LAYOUT(
  KC_ESC,   KC_PLUS, KC_MINS,
  KC_ENTER, KC_ASTR, KC_SLSH,
  KC_0,     KC_DOT,  KC_TRNS
),

/* LAYER 1
 * ,-----------------------.
 * |  ESC  |   +   |   -   |
 * |-------+-------+-------|
 * |  BSPC |   *   |   /   |
 * |-------+-------+-------|
 * |  00   |   .   |       |
 * `-----------------------'
 */
[_ADJUST] = LAYOUT(
  KC_ESC,   KC_PLUS, KC_MINS,
  KC_ENTER, KC_ASTR, KC_SLSH,
  KC_0,     KC_DOT,  KC_TRNS
)

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            //tap_code_delay(KC_VOLU, 10);
            joysitck_mode_INC();
        } else {
            //tap_code_delay(KC_VOLD, 10);
            joysitck_mode_DEC();
        }
    } else if (index == 1) { /* Second encoder */
        if (clockwise) {
            tap_code_delay(KC_VOLU, 5);
        } else {
            tap_code_delay(KC_VOLD, 5);
        }
    }
    return false;
}

#ifdef JOYSTICK_ENABLE

  int16_t xPos = 0;
  int16_t yPos = 0;

  bool wasdShiftMode = false;
  //bool autorun = false;

  bool yDownHeld = false;
  bool yUpHeld = false;
  bool xLeftHeld = false;
  bool xRightHeld = false;
  bool shiftHeld = false;

  void matrix_scan_user(void) {
    if (jMode == _WASD) {
      // W & S
      //if (!autorun) {
      yPos = analogReadPin(JSV);
        if (!yDownHeld && yPos >= _DOWN_TRESHOLD) {
          register_code(KC_S);
          yDownHeld = true;
        } else if (yDownHeld && yPos < _DOWN_TRESHOLD) {
          yDownHeld = false;
          unregister_code(KC_S);
        } else if (!yUpHeld && yPos <= _UP_TRESHOLD) {
          yUpHeld = true;
          register_code(KC_W);
        } else if (yUpHeld && yPos > _UP_TRESHOLD) {
          yUpHeld = false;
          unregister_code(KC_W);
        }
      //}
      
      xPos = analogReadPin(JSH);
      if (!xLeftHeld && xPos >= _DOWN_TRESHOLD) {
        register_code(KC_A);
        xLeftHeld = true;
      } else if (xLeftHeld && xPos < _DOWN_TRESHOLD) {
        xLeftHeld = false;
        unregister_code(KC_A);
      } else if (!xRightHeld && xPos <= _UP_TRESHOLD) {
        xRightHeld = true;
        register_code(KC_D);
      } else if (xRightHeld && xPos > _UP_TRESHOLD) {
        xRightHeld = false;
        unregister_code(KC_D);
      }
#if 0
      if (wasdShiftMode) {
        bool yShifted = yPos < _SHIFT;
        if (!shiftHeld && yShifted) {
          register_code(KC_LSFT);
          shiftHeld = true;
        } else if (shiftHeld && !yShifted) {
          unregister_code(KC_LSFT);
          shiftHeld = false;
        }
      }
#endif
    }else if(jMode == _JOYS){
      //do nothing
    }else if(jMode == _MOUSE){
    
    }else if(jMode == _SCROLL){

    }

  }

  //joystick config
  joystick_config_t joystick_axes[JOYSTICK_AXIS_COUNT] = {
    //JOYSTICK_AXIS_VIRTUAL
    //JOYSTICK_AXIS_IN(JSV, 900, 575, 285),
    //JOYSTICK_AXIS_IN(JSH, 900, 575, 285),
    JOYSTICK_AXIS_IN(JSH, _MAX, _CENTER, _MIN),
    JOYSTICK_AXIS_IN(JSV, _MIN, _CENTER, _MAX)  
  };
#endif // joystick

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        return OLED_ROTATION_180;  // flips the display 270 degrees if offhand
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status

    render_logo();

    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("DEFAULT\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJUST\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif