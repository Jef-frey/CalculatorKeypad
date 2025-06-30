#include "oled.h"
#include "calculator.h"
#include "calculator_display.h"
#include "keyboard.h"
#include "LinkedList.h"

// characters to be displayed
//display_buf cal_display;
LinkedList cal_formula;

char read_switch;
calculator cal;

void setup() {
  Serial.begin(9600);
  
  // initialization
  keyboard_initialize();
  oled_initialize();

  // display the screen as initial state
  cal.calculator_on();
}

void loop() {

  read_switch = get_pressed_switch();

  if (read_switch != '?') {
//    if keypad mode is selected
    cal.operate_input(read_switch);
    Serial.println("Hello World\n");
  }
  
}
