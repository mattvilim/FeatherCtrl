#include "config.h"
#include "Keyboard.h"

Keyboard keyboard;

void setup(void) {
#if DEBUG
  Serial.begin(9600);
  keyboard.begin();
#endif
}

void loop(void) {
  keyboard.update();
  delay(10);
}
