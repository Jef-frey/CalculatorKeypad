//'oled' will have code directly related to key switches

#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "USBHIDKeyboard.h"
#include "control.h"

const int KEY_COUNT = 17;

// GPIO48 causes issue in the design, likely due to a LED connection in my development board, the LED should not cause any issue if it is soldered off
// GPIO13 causes issue in the design, likely due to it being a MISO pin in U8G2 setting, it is possible to change but I am not sure how to
const int  KEY_PINS[KEY_COUNT] = {  39, 21, 17,  7, 15, 16, 18, 47, 38,  8, 45, 37,  3,  0, 36, 35, 14 };
const char KEY_CHAR[KEY_COUNT] = { 'N','/','*','-','+','E','9','8','7','6','5','4','3','2','1','0','.' };
const char KEY_KP[KEY_COUNT] = { KEY_NUM_LOCK,KEY_KP_SLASH,KEY_KP_ASTERISK,KEY_KP_MINUS,KEY_KP_PLUS,KEY_KP_ENTER,KEY_KP_9,KEY_KP_8,KEY_KP_7,KEY_KP_6,KEY_KP_5,KEY_KP_4,KEY_KP_3,KEY_KP_2,KEY_KP_1,KEY_KP_0,KEY_KP_DOT };

//initialize the pins as input pins with internal weak pull-up
void keyboard_initialize();

// iterate through key pins and return the button pressed, if none is pressed, return 'x'
char get_pressed_switch(calculatorkeypad_mode device_mode);

// wait until the switch was let go
void wait_until_unpressed(int pressed_pin_index);

// wait for switch debounce, then unpressed, then debounce again
void switch_debounce(int pressed_pin_index);


#endif
