#include "Keyboard.h"

Keyboard::Keyboard(void)
: matrix(), keymap() {}

void Keyboard::begin(void) {
  matrix.begin();
  hid.begin();
}

void Keyboard::update(void) {
  Matrix::Report mr;
  matrix.scan(&mr);
  Keymap::Report kr;
  keymap.update(&mr, &kr);
  hid.sendKeys();
}

