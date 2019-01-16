#include "Keyboard.h"

Keyboard::Keyboard(void)
: matrix(), keymap() {}

void Keyboard::begin(void) {
  matrix.begin();
  hid.begin();
}

void Keyboard::update(void) {
  matrix.scan();
  keymap.update(&matrix);
  hid.sendKeys();
}

