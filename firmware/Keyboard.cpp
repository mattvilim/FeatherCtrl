#include "Keyboard.h"

void Keyboard::update(void) {
  MatrixReport mr;
  matrix.scan(&mr);
  ScancodeReport sr;
  keymap.update(&mr, &sr);
  //hid_send_keys(&k->hid);
}
