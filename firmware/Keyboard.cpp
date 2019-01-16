#include "Keyboard.h"

Keyboard::Keyboard(void)
: matrix(), keymap() {}

void Keyboard::begin(void) {
  matrix.begin();
  hid.begin();
}

void Keyboard::update(void) {
  auto update = matrix.scan();
  if (update) {
    keymap.update(&matrix);
    hid.sendKeys(&keymap);
  }
}

