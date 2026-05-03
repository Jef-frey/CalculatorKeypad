// This program stores a csv file of the voltage level of the battery with respect to time
// Pressing "1" in the keypad will start storing the values and pressing "2" of the keypad will upload the file via Serial UART
// Part of the code are modified from https://dronebotworkshop.com/esp32-non-volatile-storage/

#include "control.h"
#include "oled.h"

#include "calculator_display.h"
#include "keyboard.h"

char read_switch;

display_buf display;
calculatorkeypad_mode device_mode = calculator_mode; 

#include <FS.h>
#include <LittleFS.h>

const char* FILE_PATH = "/bat_lvl.csv";
char buf[ARR_SIZE];
int write_flag = 0;
File fh;
#define LOG_INTERVAL 1000
int count = 0;
float voltage_sum = 0;

void setup() {  
  // initialization
  control_initialize();
  keyboard_initialize();
  oled_initialize();
  Serial.begin(115200);

  if (!LittleFS.begin(true)) {
    strcpy(display.top_display,"ERROR: mounting fail");
    print_calculator(display);
    return; 
  } else {
    strcpy(display.top_display,"Device ready");
    print_calculator(display);
  }

}

void loop() {
  read_switch = get_pressed_switch(device_mode);

  if (read_switch == '1') {
    if (write_flag == 0) {
      write_flag = 1;
    } else {
      write_flag = 0;
    }
  } else if (read_switch == '2') {
    String("Uploading file").toCharArray(buf, ARR_SIZE);
    strcpy(display.top_display,buf);
    print_calculator(display);

    fh = LittleFS.open(FILE_PATH, FILE_READ);
    while (fh.available()) {
      Serial.write(fh.read());
    }
    fh.close();

    String("Upload completed").toCharArray(buf, ARR_SIZE);
    strcpy(display.top_display,buf);
    print_calculator(display);

    delay(1000);
  }

  if (write_flag == 1) {
    fh = LittleFS.open(FILE_PATH, FILE_WRITE);
    fh.println("time(s),voltage(V)");
    fh.close();
    write_flag = 2;

    strcpy(display.top_display,"Recording starts");
    print_calculator(display);
    delay(1000);
  } else if (write_flag == 2){

    count++;
    voltage_sum+=readVoltage(BAT_ADC_PIN, BAT_DIVIDER_RATIO);

    static uint32_t t0 = 0;

    if (millis() - t0 >= 1000) {
      t0 = millis();

      String line = String(millis()/LOG_INTERVAL) + "," + String(voltage_sum/count, 8);
      voltage_sum = 0;
      count = 0;

      try {
        fh = LittleFS.open(FILE_PATH, FILE_APPEND);
        fh.println(line);
        fh.close();
      } catch (const std::bad_alloc& e) {
        String("Not enough memory").toCharArray(buf, ARR_SIZE);
        strcpy(display.top_display,buf);
        print_calculator(display);
        return;
      }

      size_t used = LittleFS.usedBytes();
      size_t total = LittleFS.totalBytes();

      String(String(used)+"|"+String(total)).toCharArray(buf, ARR_SIZE);
      strcpy(display.top_display,buf);

      line.toCharArray(buf, ARR_SIZE);
      strcpy(display.bottom_display,buf);

      print_calculator(display);
    }    
  }

}
