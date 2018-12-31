#include <Arduino.h>

#include "keyboard.h"

struct keyboard keyboard;

void setup(void) {
#if DEBUG
  Serial.begin(9600);
#endif

  keyboard_init(&keyboard);
}

void loop(void) {
  keyboard_loop(&keyboard);
}
