/*
 * code write for project:
 * https://github.com/Ni3nayka/wifi_pult
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru> https://github.com/Ni3nayka/
 * write:  March 2022
 * modify: March 2022
 */

// Board: LOLIN(WEMOS) D1 R2 & mini

#include "multiplexer.h"
#include "display.h"

my_display monitor;

void setup() {
  delay(1000);
  Serial.begin(9600);
  setup_multiplexer();
  monitor.setup();
  monitor.hello();
}

void loop() {
//  for (int i = 0; i<16; i++) {
//    Serial.print(read_multiplexer(i));
//    Serial.print(" ");
//  }
//  Serial.println();
  monitor.joystick_mode(read_multiplexer(0),read_multiplexer(1),read_multiplexer(2),read_multiplexer(3));
}
