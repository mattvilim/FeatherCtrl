#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "matrix.h"

struct keyboard {
  struct matrix matrix;
  //struct hid hid;
};

void keyboard_init(struct keyboard *k);
void keyboard_loop(struct keyboard *k);

#endif
