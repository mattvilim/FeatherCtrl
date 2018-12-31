#include <Arduino.h>
#include <SPI.h>

#include "bluetooth.h"
#include "config.h"-
#include "keycodes.h"
#include "keymap.h"
#include "MCP23S17.h"

struct keyboard keyboard;

void setup(void) {
  keyboard_init(&keyboard);
}

void loop(void) {
  keyboard_loop(&keyboard)
}
