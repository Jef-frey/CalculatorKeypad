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
Pins used and connected for the OLED display are written on the [`oled.cpp`](software/oled.cpp) file and the changable pins are stored on the [`oled.h`](software/oled.h) file, they are for the SPI 256x64 OLED Display with Screen Driver SH1122 used in my project, if a different display is used, a different u8g2 constructor may be used with different connections. And the SPI pins for the OLED display may also need to be changed if a different development board is used.<br />
Pins used for the keypad connections are written on the [`keyboard.h`](software/keyboard.h) file inside the variables KEY_PINS and MODE_SEL_PIN, different pins on the board can be used if available.<br />

# Battery Voltage
The original code from Olimex for battery voltage reading reads the voltage level, to display the voltage as a percentage, a script called [`plotVoltage.ino`](software/battery_level/plotVoltage.ino) is created. It measures the voltage and the time of the measurement and prints the measured values upon request. Part of this code is modified from https://dronebotworkshop.com/esp32-non-volatile-storage/ <br />
To use this script:
1. upload the script with the necessary include files at the same directory
2. charge the device with the battery until it is full
3. unplug the device and press '1' on the keypad
4. wait until the display no longer lights up (run out of power)
5. prepare a program that can accept UART signal and turn the data into a csv file (I used Tera Term for this step)
6. plug in the device at the UART port and press '2' on the keypad
7. plot the csv file

For instance this is the plot of the 420mAh Lipo battery I use
<img width="600" height="371" alt="Battery voltage output level curve" src="https://github.com/user-attachments/assets/d8e7515d-d16d-4778-a8b7-673e82791e51" />

# Reference
Software related to battery sensing is from OLIMEX, it's license GPL3 is included in this repository <br />
https://github.com/OLIMEX/ESP32-S3-DevKit-LiPo/blob/main/SOFTWARE/Arduino/ESP32-S3-DevKit-Lipo-bat-sense/ESP32-S3-DevKit-Lipo-bat-sense.ino <br />
Software related to storing data in esp32 and outputing data from esp32 is from https://dronebotworkshop.com/esp32-non-volatile-storage/

# Future plans
Add a case for the device<br />
<img width="409" height="344" alt="CalculatorKeypad_case" src="https://github.com/user-attachments/assets/cd930769-f7b3-49ed-90ec-7cee8994206a" />

Use ESP32S3 module instead of a development board, as the development board uses voltage dividers that contribute to leakage current<br />
Implement Bluetooth feature for the keypad<br />
