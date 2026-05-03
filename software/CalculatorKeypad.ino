#include "control.h"
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
battery battery_status;
int bat_flag = 1;

void IRAM_ATTR device_mode_control() {
  if (digitalRead(MODE_SEL_PIN) == HIGH) {
    cal.calculator_on();
    device_mode = calculator_mode;
  } else {
    bat_flag = 1;
    battery_status = get_bat_status(bat_flag);
    print_battery(battery_status);
    device_mode = keypad_mode;
    bat_flag = 0;
  }
}

void setup() {  
  // initialization
  control_initialize();
  keyboard_initialize();
  oled_initialize();

  Keyboard.begin();
  USB.begin();

  attachInterrupt(MODE_SEL_PIN, device_mode_control, CHANGE);

  // display the screen's initial state 
  device_mode_control();

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

  if (device_mode == keypad_mode) {
    battery_status = get_bat_status(bat_flag);
    print_battery(battery_status);
  }
}

// 