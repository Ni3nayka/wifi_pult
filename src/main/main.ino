/* * code write for project:
 * https://github.com/Ni3nayka/wifi_pult
 * 
 * author: Egor Bakay <egor_bakay@inbox.ru> https://github.com/Ni3nayka/
 * write:  March 2022
 * modify: March 2022
 */

// Board: LOLIN(WEMOS) D1 R2 & mini

#include "joystick.h"
#include "display.h"

my_display monitor;
my_joystick joystick;

void setup() {
  delay(1000);
  Serial.begin(9600);
  setup_multiplexer();
  monitor.setup();
  monitor.hello();
}

void loop() {
  joystick.update();
  //joystick_mode(int xl=0, int yl=0, int xr=0, int yr=0, int button_jl=0, int button_jr=0, int button_l=0, int button_r=0, bool connect=0) {
  monitor.joystick_mode(joystick.LX,joystick.LY,joystick.RX,joystick.RY,joystick.LZ,joystick.RZ,joystick.LB,joystick.RB);
  joystick.print_multiplexer();
}
