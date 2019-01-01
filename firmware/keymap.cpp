#include "keymap.h"

#include "matrix.h"

void keymap_init(struct keymap *k) {
  k->active_layer = KEYMAP_LAYER_BASE;
}

void keymap_update(struct keymap *k) {
}

//const enum keymap_key layers[KEYMAP_LAYER_COUNT][MATRIX_ROW_NUM][MATRIX_COL_NUM] = {
//};
