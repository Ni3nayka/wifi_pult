/*
 * code write for project:
 * https://github.com/Ni3nayka/wifi_pult
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru> https://github.com/Ni3nayka/
 * write:  March 2022
 * modify: March 2022
 */

// Board: LOLIN(WEMOS) D1 R2 & mini

#pragma once

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino resetpin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

class my_display {
  public:
    void setup() {
      if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
      }
    }
    void clear() {
      display.clearDisplay();
    }
    void update() {
      
    }
  private:
  
};
