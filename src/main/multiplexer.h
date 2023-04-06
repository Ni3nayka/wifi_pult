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

#define MULTIPLEXER_PIN_S0 D7
#define MULTIPLEXER_PIN_S1 D6
#define MULTIPLEXER_PIN_S2 D5
#define MULTIPLEXER_PIN_S3 D0
#define MULTIPLEXER_PIN_A A0

#define VOLTAGE_PIN 8

void setup_multiplexer() {
  pinMode(MULTIPLEXER_PIN_A,OUTPUT);
  pinMode(MULTIPLEXER_PIN_S0,OUTPUT);
  pinMode(MULTIPLEXER_PIN_S1,OUTPUT);
  pinMode(MULTIPLEXER_PIN_S2,OUTPUT);
  pinMode(MULTIPLEXER_PIN_S3,OUTPUT);
}

int read_multiplexer(int number) {
  if (number<0 || number>15) return -1;
  digitalWrite(MULTIPLEXER_PIN_S0,number%2);
  digitalWrite(MULTIPLEXER_PIN_S1,(number>>1)%2);
  digitalWrite(MULTIPLEXER_PIN_S2,(number>>2)%2);
  digitalWrite(MULTIPLEXER_PIN_S3,(number>>3)%2);
  delay(1);
  return analogRead(MULTIPLEXER_PIN_A);
}

float voltage() {
  return read_multiplexer(VOLTAGE_PIN);
}
