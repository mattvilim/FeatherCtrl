#ifndef KEYMAP_H
#define KEYMAP_H

enum keymap_key {
  KEYMAP_KEY_A,
  KEYMAP_KEY_B,
};

#define KEYMAP_LAYER_COUNT 2

struct keymap {
  unsigned char active_layer;
};

void keymap_init(struct keymap *k);

#endif
