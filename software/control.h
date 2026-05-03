//'control' will have code directly related to the functionalities for battery and mode switching function

// MODE_SEL_PIN is the pin used for switching between calculator mode and keypad mode
// PG_PIN is power good for the battery, indicate any issue with the charging
// CHG_PIN is charging for the battery, indicate if the battery finish charging

// battery sensor code from OLIMEX will be used 

#ifndef CONTROL_H
#define CONTROL_H
#include <cstdint>

enum calculatorkeypad_mode{
  calculator_mode,
  keypad_mode
};

struct battery{
  bool pwr;
  float bat;
};

#define MODE_SEL_PIN   1
#define BAT_ADC_PIN    6    // GPIO6 (Battery)
#define PWR_ADC_PIN    5    // GPIO5 (External power)

//////////////////////////////////////////////////////////////
// ------------- ADC CONFIGURATION -------------------------
//////////////////////////////////////////////////////////////

#define ADC_RESOLUTION 4095.0
#define ADC_REF        3.3

// Correct ratios from schematic
#define BAT_DIVIDER_RATIO  4.1333
#define PWR_DIVIDER_RATIO  5.6808

// 5V through divider gives ~880mV at ADC
// Anything above 400mV means external power present
#define PWR_PRESENT_THRESHOLD 400

#define BAT_UPDATE_INTERVAL 1000

void control_initialize();

// return status of the battery
battery get_bat_status(int bat_flag);

float readVoltage(uint8_t pin, float dividerRatio);

uint16_t readRawMilliVolts(uint8_t pin);

#endif
