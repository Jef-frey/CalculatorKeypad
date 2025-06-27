//'oled' will have code directly related to key switches

#ifndef KEYBOARD_H
#define KEYBOARD_H

const int KEY_COUNT = 17;
const int  KEY_PINS[KEY_COUNT] = {  21, 47, 4, 45,  0, 35, 36, 37, 38, 39, 40, 41, 42,  2,  1, 44, 43 };
const char KEY_CHAR[KEY_COUNT] = { 'N','/','*','-','+','E','9','8','7','6','5','4','3','2','1','0','.' };

//initialize the pins as input pins with internal weak pull-up
void keyboard_initialize();

// iterate through key pins and return the button pressed, if none is pressed, return 'x'
char get_pressed_switch();

// wait until the switch was let go
void wait_until_unpressed(int pressed_pin_index);

// wait for switch debounce, then unpressed, then debounce again
void switch_debounce(int pressed_pin_index);


#endif
