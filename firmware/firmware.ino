#include <Arduino.h>

#include "config.h"
#include "keyboard.h"

Keyboard keyboard;

void setup(void) {
#if DEBUG
  Serial.begin(9600);
#endif

  keyboard_init(&keyboard);
}

void loop(void) {
  keyboard_loop(&keyboard);
}
