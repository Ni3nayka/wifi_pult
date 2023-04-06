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

#include "multiplexer.h"

#define JOYSTICK_LX 4
#define JOYSTICK_LY 5
#define JOYSTICK_LZ 3
#define JOYSTICK_RX 1
#define JOYSTICK_RY 0
#define JOYSTICK_RZ 2
#define JOYSTICK_LB 6
#define JOYSTICK_RB 7

int translate_one_joystick(int a, int min, int available, int max) {
  return constrain(a>available?map(a,available,max,0,100):map(a,min,available,-100,0),-100,100);
}

class my_joystick {
  public:
    int LX,LY,LZ,LB,RX,RY,RZ,RB;
    void print_multiplexer() {
      for (int i = 0; i<16; i++) {
        Serial.print(read_multiplexer(i));
        Serial.print(" ");
      }
      Serial.println();
    }
    void update() {
      LX = translate_one_joystick(read_multiplexer(JOYSTICK_LX),20,283,1010)*0.4+LX*0.6;
      LY = translate_one_joystick(read_multiplexer(JOYSTICK_LY),20,306,1010)*0.4+LY*0.6;
      //LX = map(LX1,)
      LZ = read_multiplexer(JOYSTICK_LZ)<100;
      LB = read_multiplexer(JOYSTICK_LB)<100;
      RX = translate_one_joystick(read_multiplexer(JOYSTICK_RX),20,290,1000)*0.4+RX*0.6;
      RY = translate_one_joystick(read_multiplexer(JOYSTICK_RY),20,308,995)*0.4+RY*0.6;
      RZ = read_multiplexer(JOYSTICK_RZ)<100;
      RB = read_multiplexer(JOYSTICK_RB)<100;
    }
    float voltage() {
      return read_multiplexer(VOLTAGE_PIN);
    }
  private:
    int LX1,LY1,RX1,RY1;
};
