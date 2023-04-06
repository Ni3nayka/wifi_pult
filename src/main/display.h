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
    void hello() {
      display.clearDisplay();
      display.setTextColor(WHITE);
//      display.setTextSize(2);
//      display.setCursor(1, 28);
//      display.println("Hello world!");
//      display.display();
//      delay(500);
//      display.startscrollleft(0x00, 0x07);
//      delay(4500);
//      display.stopscroll();
//      delay(1000);
      display.setTextSize(1);
      display.setCursor(25, 15);
      display.println("Hello world!");
      display.display();
      delay(500);
      display.setCursor(0, 30);
      for (int i = 0; i<21; i++) {
        display.print("#");
        display.display();
        delay(50);
      }
      display.setCursor(20, 45);
      display.println("Start joystick");
      display.display();
      delay(1500);
    }
    void joystick_mode(int xl=0, int yl=0, int xr=0, int yr=0, int button_jl=0, int button_jr=0, int button_l=0, int button_r=0, bool connect=0) {
      display.clearDisplay();
      display.setTextColor(WHITE);
      display.setTextSize(1);
      
      //display.setCursor(0, 28);
      //display.setCursor(0, 56);

      display.setCursor(20, 0);
      display.print("Joystick mode:");
      display.setCursor(27, 9);
      display.print("Connect: ");
      display.print(connect?"yes":"no");

      display.setCursor(0, 20);
      display.print("Left:");
      display.setCursor(0, 29);
      display.print("X: ");
      display.print(xl);
      display.setCursor(0, 38);
      display.print("Y: ");
      display.print(yl);
      display.setCursor(0, 47);
      display.print("Z: ");
      display.print(button_jl);
      display.setCursor(0, 56);
      display.print("B: ");
      display.print(button_l);

      display.setCursor(86, 20);
      display.print("Right:");
      display.setCursor(86, 29);
      display.print("X: ");
      display.print(xr);
      display.setCursor(86, 38);
      display.print("Y: ");
      display.print(yr);
      display.setCursor(86, 47);
      display.print("Z: ");
      display.print(button_jr);
      display.setCursor(86, 56);
      display.print("B: ");
      display.print(button_r);

      display.display();
      
    }
  private:
  
};
