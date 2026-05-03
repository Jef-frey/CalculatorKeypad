#include "control.h"
#include <arduino.h>

// battery sensor code from OLIMEX will be used 
// https://github.com/OLIMEX/ESP32-S3-DevKit-LiPo/blob/main/SOFTWARE/Arduino/ESP32-S3-DevKit-Lipo-bat-sense/ESP32-S3-DevKit-Lipo-bat-sense.ino

uint16_t bat_read_cnt;
float sum;
float batteryVoltage;

void control_initialize() {
  pinMode(MODE_SEL_PIN, INPUT_PULLUP);
  analogReadResolution(12);

  bat_read_cnt = 0;
  sum = 0;
  batteryVoltage = 0;
}

battery get_bat_status(int bat_flag) {
  battery temp;

  if (bat_flag) {
    batteryVoltage = readVoltage(BAT_ADC_PIN, BAT_DIVIDER_RATIO);
    bat_read_cnt = 0;
  } else {
    bat_read_cnt++;
    sum+=readVoltage(BAT_ADC_PIN, BAT_DIVIDER_RATIO);
    if (bat_read_cnt > BAT_UPDATE_INTERVAL) {
      batteryVoltage = sum/bat_read_cnt;
      sum = 0;
      bat_read_cnt = 0;
    }
  }
  
  uint16_t pwrRawMv = readRawMilliVolts(PWR_ADC_PIN);

  bool externalPowerPresent = (pwrRawMv > PWR_PRESENT_THRESHOLD);

  temp.pwr = externalPowerPresent;
  temp.bat = batteryVoltage;

  return temp;
}

float readVoltage(uint8_t pin, float dividerRatio)
{
  uint32_t adcRaw = analogRead(pin);

  float adcVoltage = (adcRaw / ADC_RESOLUTION) * ADC_REF;
  float realVoltage = adcVoltage * dividerRatio;

  return realVoltage;
}

uint16_t readRawMilliVolts(uint8_t pin)
{
  uint32_t adcRaw = analogRead(pin);
  float adcVoltage = (adcRaw / ADC_RESOLUTION) * ADC_REF;
  return (uint16_t)(adcVoltage * 1000.0);
}
