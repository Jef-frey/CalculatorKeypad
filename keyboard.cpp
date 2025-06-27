#include "keyboard.h"
#include <arduino.h>

void keyboard_initialize() {
  for (int i = 0; i < KEY_COUNT; i++) {
    pinMode(KEY_PINS[i], INPUT_PULLUP);
  }
}

char get_pressed_switch() {

  for (int i = 0; i < KEY_COUNT; i++) {
    if (digitalRead(KEY_PINS[i]) == LOW) {
      switch_debounce(i);
      return KEY_CHAR[i];
    }
  }

  return '?';
}


void wait_until_unpressed(int pressed_pin_index) {
  if (digitalRead(KEY_PINS[pressed_pin_index]) == LOW) {
      while((digitalRead(KEY_PINS[pressed_pin_index]) == LOW)) {}
      return;
  }

  return;
}

void switch_debounce(int pressed_pin_index) {
  delay(5);
  wait_until_unpressed(pressed_pin_index);
  delay(5);
}
