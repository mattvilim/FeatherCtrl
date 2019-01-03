#include <Arduino.h>

#include "config.h"
#include "Keyboard.h"

Keyboard keyboard;

void setup(void) {
#if DEBUG
  Serial.begin(9600);
#endif
}

void loop(void) {
  keyboard.update();
}
