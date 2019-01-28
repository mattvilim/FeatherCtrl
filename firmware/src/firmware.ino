#include "config.h"
#include "Keyboard.h"

Keyboard keyboard;

void setup(void) {
#if DEBUG
  Serial.begin(9600);
#endif
  keyboard.begin();

  pinMode(PIN_NEOPIXEL, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(PIN_NEOPIXEL, LOW);
}

void loop(void) {
  keyboard.update();
  // sleep to save power
  delay(10);
  digitalWrite(PIN_NEOPIXEL, LOW);
}
