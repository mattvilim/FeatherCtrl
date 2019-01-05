#include "Keyboard.h"

Keyboard::Keyboard(void)
: matrix(), keymap() {}

void Keyboard::update(void) {
  Matrix::Report mr;
  matrix.scan(&mr);
  Keymap::Report kr;
  keymap.update(&mr, &kr);
  //hid_send_keys(&k->hid);
}

void Keyboard::begin(void) {
  matrix.begin();
}
