//'control' will have code directly related to the functionalities for battery and mode switching function

// MODE_SEL_PIN is the pin used for switching between calculator mode and keypad mode
// PG_PIN is power good for the battery, indicate any issue with the charging
// CHG_PIN is charging for the battery, indicate if the battery finish charging

#ifndef CONTROL_H
#define CONTROL_H

enum calculatorkeypad_mode{
  calculator_mode,
  keypad_mode
};

struct battery{
  bool pg;
  bool chg;
};

const int MODE_SEL_PIN = 6;
const int PG_PIN = 4;
const int CHG_PIN = 5;

void control_initialize();

// return status of the battery
battery get_bat_status();

#endif