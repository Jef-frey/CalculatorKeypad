#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard Keyboard;

const int KEY_COUNT = 17;
const int  KEY_PINS[KEY_COUNT] = {  21, 47, 4, 45,  0, 35, 36, 37, 38, 39, 40, 41, 42,  2,  1, 44, 43 };
const char KEY_KP[KEY_COUNT] = { KEY_NUM_LOCK,KEY_KP_SLASH,KEY_KP_ASTERISK,KEY_KP_MINUS,KEY_KP_PLUS,KEY_KP_ENTER,KEY_KP_9,KEY_KP_8,KEY_KP_7,KEY_KP_6,KEY_KP_5,KEY_KP_4,KEY_KP_3,KEY_KP_2,KEY_KP_1,KEY_KP_0,KEY_KP_DOT };

enum calculatorkeypad_mode{
  calculator,
  keypad
};

int mode_sel_pin = 7;

calculatorkeypad_mode device_mode; 

char read_switch;

void setup() {
  for (int i = 0; i < KEY_COUNT; i++) {
    pinMode(KEY_PINS[i], INPUT_PULLUP);
  }
  pinMode(mode_sel_pin, INPUT_PULLUP);

  Keyboard.begin();
  USB.begin();
}

void loop() {

  read_switch = get_pressed_switch();

  if (read_switch != '?') {
    if(digitalRead(mode_sel_pin) == HIGH) {
  //    if keypad mode is selected
      Keyboard.write(read_switch);
    } else {
      // calculator operation
    }
    
  }
  

}

char get_pressed_switch() {

  for (int i = 0; i < KEY_COUNT; i++) {
    if (digitalRead(KEY_PINS[i]) == LOW) {
      switch_debounce(i);
      return KEY_KP[i];
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

// +5869310..0123456789+--*/33555555555536
