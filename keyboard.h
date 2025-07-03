//'oled' will have code directly related to key switches

#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "USBHIDKeyboard.h"

const int KEY_COUNT = 17;
const int MODE_SEL_PIN = 5;

const int  KEY_PINS[KEY_COUNT] = {  21, 47, 4, 45,  0, 35, 36, 37, 38, 39, 40, 41, 42,  2,  1, 44, 43 };
const char KEY_CHAR[KEY_COUNT] = { 'N','/','*','-','+','E','9','8','7','6','5','4','3','2','1','0','.' };
const char KEY_KP[KEY_COUNT] = { KEY_NUM_LOCK,KEY_KP_SLASH,KEY_KP_ASTERISK,KEY_KP_MINUS,KEY_KP_PLUS,KEY_KP_ENTER,KEY_KP_9,KEY_KP_8,KEY_KP_7,KEY_KP_6,KEY_KP_5,KEY_KP_4,KEY_KP_3,KEY_KP_2,KEY_KP_1,KEY_KP_0,KEY_KP_DOT };

enum calculatorkeypad_mode{
  calculator_mode,
  keypad_mode
};

//initialize the pins as input pins with internal weak pull-up
void keyboard_initialize();

// iterate through key pins and return the button pressed, if none is pressed, return 'x'
char get_pressed_switch(calculatorkeypad_mode device_mode);

// wait until the switch was let go
void wait_until_unpressed(int pressed_pin_index);

// wait for switch debounce, then unpressed, then debounce again
void switch_debounce(int pressed_pin_index);


#endif
