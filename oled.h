//My ESP32-S3 DevBoard has the following default SPI pins
//MOSI  | SDA : 11
//MISO  : 13
//SCK   | SCL : 12
//SS    | CS  : 10

//My OLED Display is 256*64 with SH1122 Controller

#ifndef OLED_H
#define OLED_H

const int RST_PIN = 10;
const int DC_PIN = 9;
const int CS_PIN = 46;

void oled_initialize();

void update_formula(char *row_1, char *row_2);

#endif
