#include "oled.h"

#include "calculator.h"
#include "calculator_display.h"
#include "keyboard.h"
#include "LinkedList.h"

#include "USB.h"
#include "USBHIDKeyboard.h"

char read_switch;
calculator cal;
USBHIDKeyboard Keyboard;
calculatorkeypad_mode device_mode; 
calculatorkeypad_mode prev_device_mode; 

void IRAM_ATTR device_mode_control() {
  if (digitalRead(MODE_SEL_PIN) == HIGH) {
    cal.calculator_on();
    device_mode = calculator_mode;
  } else {
    print_keypad();
    device_mode = keypad_mode;
  }
}

void setup() {  
  // initialization
  keyboard_initialize();
  oled_initialize();

  Keyboard.begin();
  USB.begin();

  attachInterrupt(MODE_SEL_PIN, device_mode_control, CHANGE);

  // display the screen as initial state if device is on calculator_mode 
  if (digitalRead(MODE_SEL_PIN) == HIGH) {
    cal.calculator_on();
    device_mode = calculator_mode;
  } else {
    print_keypad();
    device_mode = keypad_mode;
  }
}

void loop() {


  read_switch = get_pressed_switch(device_mode);

  if (read_switch != '?') {
    if (device_mode == keypad_mode) {
      Keyboard.write(read_switch);
    } else {
      cal.operate_input(read_switch);
    }
  }
  
}

