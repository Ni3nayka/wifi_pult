/*
 * code write for project:
 * https://github.com/Ni3nayka/wifi_pult
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru> https://github.com/Ni3nayka/
 * write:  March 2022
 * modify: March 2022
 */

#pragma once

#define MULTIPLEXER_S1 D7
#define MULTIPLEXER_S2 D3
#define MULTIPLEXER_S3 D4
#define MULTIPLEXER_A  A0

void setup_multiplexer() {
  pinMode(MULTIPLEXER_S1,OUTPUT);
  pinMode(MULTIPLEXER_S2,OUTPUT);
  pinMode(MULTIPLEXER_S3,OUTPUT);
  pinMode(MULTIPLEXER_A,INPUT);
}

int get_multiplexer(int n) {
  if (n<0 || n>7) return 0;
  digitalWrite(MULTIPLEXER_S1,n%2);
  digitalWrite(MULTIPLEXER_S2,(n>>1)%2);
  digitalWrite(MULTIPLEXER_S3,(n>>2)%2);
  return analogRead(MULTIPLEXER_A);
}
