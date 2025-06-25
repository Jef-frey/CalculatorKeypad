#include "keyboard.h"
#include <arduino.h>

void keyboard_initialize() {
  for (int i = 0; i < SRC_COUNT; i++) {
    pinMode(SRC_PINS[i], OUTPUT);
    digitalWrite(SRC_PINS[i], HIGH);
  }

  for (int i = 0; i < DRN_COUNT; i++) {
    pinMode(DRN_PINS[i], INPUT_PULLUP);
  }

}

// iterate through and check if button is pressed
char get_pressed_switch() {

  for (int i = 0; i < SRC_COUNT; i++) {
    digitalWrite(SRC_PINS[i], HIGH);
    digitalWrite(SRC_PINS[(i+1)%SRC_COUNT], LOW);

    delay(1);
    
    for (int j = 0; j < DRN_COUNT; j++) {
      if (digitalRead(DRN_PINS[j]) == LOW) {
        return KEYPAD[(i+1)%SRC_COUNT][j];
      }
    }
  }

  return ' ';
}

// wait until the switch was let go
void wait_until_unpressed() {
  for (int i = 0; i < DRN_COUNT; i++) {
    if (digitalRead(DRN_PINS[i]) == LOW) {
      while((digitalRead(DRN_PINS[i]) == LOW)) {}
      return;
    }
  }

  return;
}

void switch_debounce() {
  delay(5);
  wait_until_unpressed();
  delay(5);
}

//  find if char_in is an operator +-*/
bool isoperator(char char_in){
  if (char_in == '+' || char_in == '-' || char_in == '*' || char_in == '/') {
    return true;
  } else {
    return false;
  }
}
