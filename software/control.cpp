#include "control.h"
#include <arduino.h>

// battery sensor code from OLIMEX will be used 
// https://github.com/OLIMEX/ESP32-S3-DevKit-LiPo/blob/main/SOFTWARE/Arduino/ESP32-S3-DevKit-Lipo-bat-sense/ESP32-S3-DevKit-Lipo-bat-sense.ino

void control_initialize() {
  pinMode(MODE_SEL_PIN, INPUT_PULLUP);
  analogReadResolution(12);

}

battery get_bat_status() {
  battery temp;

  float batteryVoltage = readVoltage(BAT_ADC_PIN, BAT_DIVIDER_RATIO);
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
