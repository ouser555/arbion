/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#pragma once


// Min 0, max 32
#define JOYSTICK_BUTTON_COUNT 16
// Min 0, max 6: X, Y, Z, Rx, Ry, Rz
#define JOYSTICK_AXIS_COUNT 2
// Min 8, max 16
#define JOYSTICK_AXIS_RESOLUTION 10 // for AVR
// 12-bit for most STM32

//ENC
//#define DT C6
//#define CK D4
#define ENCODERS_PAD_A { C6 }
#define ENCODERS_PAD_B { D4 }
//#define ENCODER_DIRECTION_FLIP
//#define ENCODER_RESOLUTION 4
//#define ENCODER_DEFAULT_POS 0x3
//#define ENCODER_MAP_KEY_DELAY 10

//JOYSTICK
#define JSV F4 //A3
#define JSH F5 //A2

#define ANALOG_JOYSTICK_X_AXIS_PIN F5
#define ANALOG_JOYSTICK_Y_AXIS_PIN F4
#define POINTING_DEVICE_INVERT_X

#define _MIN 0
#define _MAX 1023
#define _CENTER 512
#define _DEAD 20
#define _SHIFT 15 // last 15 steps upwards

#define _DOWN_TRESHOLD (_CENTER+_DEAD)
#define _UP_TRESHOLD (_CENTER-_DEAD)

//BTN
#define JSB F6 //A1
#define BTN_1 E6 //7
#define BTN_2 B4 //8
#define BTN_3 B5 //9
//OLED
#define SDA D2
#define SCL D3
//KEYSCAN
/* 9Key PCB default pin-out */
#define MATRIX_ROW_PINS { D1, D0, B6 }
#define MATRIX_COL_PINS { B1, B3, B2 }


/* ws2812 RGB LED */
#define RGB_DI_PIN F7
#define RGBLED_NUM 1    // Number of LEDs

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define TAPPING_TERM 200
