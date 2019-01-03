#include "keyboard.h"

void keyboard_init(struct keyboard *k) {
  matrix_init(&k->matrix);
  keymap_init(&k->keymap);
  //hid_init(&k->hid);
}

void keyboard_loop(struct keyboard *k) {
  matrix_report mr;
  matrix_scan(&k->matrix, &mr);
  scancode_report sr;
  keymap_update(&k->keymap, &mr, &sr);
  //hid_send_keys(&k->hid);
}
