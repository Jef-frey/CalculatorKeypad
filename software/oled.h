//'oled' will have code directly related to printing on OLED display

//My ESP32-S3 DevBoard has the following default SPI pins
//MOSI  | SDA : 11
//MISO  : 13
//SCK   | SCL : 12
//SS    | CS  : 10

//My OLED Display is 256*64 with SH1122 Controller

//Connection between ESP32 and OLED can be modified, but for this version of the design it is the following:
//  GND VCC SCL SDA RST DC  CS
//  GND 3V3 12  11  10  9   46

#ifndef OLED_H
#define OLED_H
#include "calculator_display.h"

const int RST_PIN = 10;
const int DC_PIN = 9;
const int CS_PIN = 46;

void oled_initialize();

void print_calculator(display_buf calculator_display);

// output status of the battery to screen
void print_battery(bool pg, bool chg);

#endif
