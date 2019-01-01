#include "keyboard.h"

void keyboard_init(struct keyboard *k) {
  matrix_init(&k->matrix);
}

void keyboard_loop(struct keyboard *k) {
  matrix_scan(&k->matrix);
  keymap_update(&k->keymap);
  hid_send_keys(&k->hid);
}
