#include "Keyboard.h"

Keyboard::Keyboard(void)
: matrix(), keymap(), hid() {}

void Keyboard::begin(void) {
  hid.begin();
  matrix.begin();
}

void Keyboard::update(void) {
  auto update = matrix.scan();
  if (update) {
    keymap.update(&matrix);
    hid.sendKeys(&keymap);
  }
}

