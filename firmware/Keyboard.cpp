#include "Keyboard.h"

Keyboard::Keyboard(void)
: matrix(), keymap() {}

void Keyboard::update(void) {
  Matrix::report mr;
  matrix.scan(&mr);
  Keymap::Report kr;
  keymap.update(&mr, &kr);
  //hid_send_keys(&k->hid);
}
