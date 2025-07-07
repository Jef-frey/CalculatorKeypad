#include "control.h"
#include <arduino.h>

void control_initialize() {
  pinMode(MODE_SEL_PIN, INPUT_PULLUP);
  pinMode(PG_PIN, INPUT);
  pinMode(CHG_PIN, INPUT);
}

battery get_bat_status() {
  battery temp;
  if (digitalRead(PG_PIN) == LOW) {
    temp.pg = true;
  } else {
    temp.pg = false;
  }
  if (digitalRead(CHG_PIN) == LOW) {
    temp.chg = true;
  } else {
    temp.chg = false;
  }
  return temp;
}