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

void setup() {
  Serial.begin(9600);
  //setup_multiplexer();
  
}

void loop() {
//  for (int i = 0; i<8; i++) {
//    Serial.print(get_multiplexer(i));
//    Serial.print(" ");
//  }
//  Serial.println();
//  delay(200);
  Serial.println(analogRead(A0));
  delay(200);
}
