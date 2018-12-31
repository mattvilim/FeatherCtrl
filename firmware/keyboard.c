#include "keyboard.h"

void keyboard_init(struct keyboard *k) {
  matrix_init(&k->matrix);
}

void keyboard_loop(struct keyboard *k) {
  matrix_scan(&k->matrix);
}
