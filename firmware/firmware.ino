#include "config.h"
#include "Keyboard.h"

Keyboard keyboard;

void setup(void) {
  keyboard.begin();
#if DEBUG
  Serial.begin(9600);
#endif
}

void loop(void) {
  keyboard.update();
  // sleep to save power
  delay(10);
}
