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

void setup() {
  Serial.begin(9600);
  
  // initialization
  keyboard_initialize();
  oled_initialize();

  // display the screen as initial state if device is on calculator_mode 
  if (digitalRead(MODE_SEL_PIN) == HIGH) {
    cal.calculator_on();
    device_mode = calculator_mode;
    prev_device_mode = calculator_mode;
  } else {
    print_keypad();
    device_mode = keypad_mode;
    prev_device_mode = keypad_mode;
  }
}

void loop() {

  // if (digitalRead(MODE_SEL_PIN) == HIGH) {
  //   device_mode = calculator_mode;
  //   if (prev_device_mode != device_mode) {
  //     cal.calculator_on();
  //     prev_device_mode = calculator_mode;
  //   }
  // } else {
  //   device_mode = keypad_mode;
  //   if (prev_device_mode != device_mode) {
  //     print_keypad();
  //     prev_device_mode = keypad_mode;
  //   }
  // }
  
  if (digitalRead(MODE_SEL_PIN) == HIGH) {
    device_mode = calculator_mode;
  } else {
    device_mode = keypad_mode;
  }

  read_switch = get_pressed_switch(device_mode);

  if (read_switch != '?') {
    if (digitalRead(MODE_SEL_PIN) == HIGH) {
      Keyboard.write(read_switch);
    } else {
      cal.operate_input(read_switch);
    }
    
  }
  
}
