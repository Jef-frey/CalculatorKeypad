# CalculatorKeypad(WIP)
This project is still a work in progress, the goal is to create a device that can switch between calculator and computer keypad function with the flip of a switch 
![alt_text](https://github.com/Jef-frey/CalculatorKeypad/blob/43f4f6bfeb75b3e98396a056e46a6a369680fc8d/CalculatorKeypad_prototype.jpg?raw=true)

# Requirements
## Hardware
1x ESP32S3 development board<br />
1x OLED display<br />
2x USB cables<br />
1x slide switch<br />
Switches that fit your application (17 for my project)<br />

## Software
Arduino IDE<br />
U8G2 library<br />

# Connection
Pins used and connected for the OLED display are written on the [`oled.cpp`](https://github.com/Jef-frey/CalculatorKeypad/blob/43f4f6bfeb75b3e98396a056e46a6a369680fc8d/oled.cpp) file and the changable pins are stored on the [`oled.h`](https://github.com/Jef-frey/CalculatorKeypad/blob/43f4f6bfeb75b3e98396a056e46a6a369680fc8d/oled.h) file, they are for the SPI 256x64 OLED Display with Screen Driver SH1122 used in my project, if a different display is used, a different u8g2 constructor may be used with different connections. And the SPI pins for the OLED display may also need to be changed if a different development board is used.<br />
Pins used for the keypad connections are written on the [`keyboard.h`](https://github.com/Jef-frey/CalculatorKeypad/blob/43f4f6bfeb75b3e98396a056e46a6a369680fc8d/keyboard.h) file inside the variables KEY_PINS and MODE_SEL_PIN, different pins on the board can be used if available.<br />

# Future plans
Add a Lipo battery and charging circuit to make the device portable<br />
Design a PCB board for this device<br />
![alt_text](https://github.com/Jef-frey/CalculatorKeypad/blob/e9a229c3cd5ce73293fd050ed53fb9cd7fbbe299/CalculatorKeypad.png)
Use ESP32S3 module instead of a development board<br />
Implement Bluetooth feature for the keypad<br />
