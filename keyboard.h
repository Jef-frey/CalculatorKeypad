#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdbool.h>
#include <ctype.h>

const int SRC_COUNT = 5;
const int DRN_COUNT = 4;

const int SRC_PINS[SRC_COUNT] = { 16, 21, 17, 32, 22 };
const int DRN_PINS[DRN_COUNT] = { 1, 3, 5, 0 };
const char KEYPAD[SRC_COUNT][DRN_COUNT] = {
  {'N','N','N','N'},
  {'/','*','-','+'},
  {'6','7','8','9'},
  {'2','3','4','5'},
  {'0','1','.','E'}
};

void keyboard_initialize();

char get_pressed_switch();

void wait_until_unpressed();

void switch_debounce();

bool isoperator(char char_in);

#endif
