# CalculatorKeypad(WIP)
This project is still a work in progress, the goal is to create a device that can switch between calculator and computer keypad function with the flip of a switch 
<img width="514" height="565" alt="keypad_mode" src="https://github.com/user-attachments/assets/b3ec0a80-4e9a-4d7a-82a1-fcebf6f34e78" />
<img width="533" height="614" alt="calculator_mode" src="https://github.com/user-attachments/assets/49f07bc2-d8c0-4ed5-8083-b835f50fa5a4" />

# Requirements
## Hardware
1x OLIMEX ESP32-S3-DevKit-LiPo development board<br />
1x OLED display<br />
1x battery<br />
1x USB cables<br />
2x slide switch<br />
Switches that fit your application (17 for my project)<br />

## Software
Arduino IDE<br />
U8G2 library<br />
 
# Connection
Pins used and connected for the OLED display are written on the [`oled.cpp`](https://github.com/Jef-frey/CalculatorKeypad/blob/43f4f6bfeb75b3e98396a056e46a6a369680fc8d/oled.cpp) file and the changable pins are stored on the [`oled.h`](https://github.com/Jef-frey/CalculatorKeypad/blob/43f4f6bfeb75b3e98396a056e46a6a369680fc8d/oled.h) file, they are for the SPI 256x64 OLED Display with Screen Driver SH1122 used in my project, if a different display is used, a different u8g2 constructor may be used with different connections. And the SPI pins for the OLED display may also need to be changed if a different development board is used.<br />
Pins used for the keypad connections are written on the [`keyboard.h`](https://github.com/Jef-frey/CalculatorKeypad/blob/43f4f6bfeb75b3e98396a056e46a6a369680fc8d/keyboard.h) file inside the variables KEY_PINS and MODE_SEL_PIN, different pins on the board can be used if available.<br />

# Reference
Software related to battery sensing is from OLIMEX, it's license GPL3 is included in this repository <br />
https://github.com/OLIMEX/ESP32-S3-DevKit-LiPo/blob/main/SOFTWARE/Arduino/ESP32-S3-DevKit-Lipo-bat-sense/ESP32-S3-DevKit-Lipo-bat-sense.ino

# Future plans
Add a case for the device<br />
Use ESP32S3 module instead of a development board<br />
Implement Bluetooth feature for the keypad<br />
