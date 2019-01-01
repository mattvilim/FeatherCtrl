#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "matrix.h"
#include "keymap.h"
#include "hid.h"

struct keyboard {
  struct matrix matrix;
  struct keymap keymap;
  struct hid hid;
};

void keyboard_init(struct keyboard *k);
void keyboard_loop(struct keyboard *k);

#endif
