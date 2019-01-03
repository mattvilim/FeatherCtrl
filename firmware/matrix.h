#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

enum matrix_row {
  MATRIX_ROW1,
  MATRIX_ROW2,
  MATRIX_ROW3,
  MATRIX_ROW4,
  MATRIX_ROW5,
  MATRIX_ROW6,
  MATRIX_ROW7,
  MATRIX_ROW_COUNT
};

enum matrix_col {
  MATRIX_COL_A,
  MATRIX_COL_B,
  MATRIX_COL_C,
  MATRIX_COL_D,
  MATRIX_COL_E,
  MATRIX_COL_F,
  MATRIX_COL_G,
  MATRIX_COL_H,
  MATRIX_COL_I,
  MATRIX_COL_J,
  MATRIX_COL_K,
  MATRIX_COL_L,
  MATRIX_COL_M,
  MATRIX_COL_N,
  MATRIX_COL_O,
  MATRIX_COL_COUNT
};

struct matrix_report {
  uint16_t pressed[MATRIX_ROW_COUNT];
  uint16_t released[MATRIX_ROW_COUNT];
};

struct matrix_key {
  uint8_t pressed : 1;
  uint8_t press_time : 7;
};

struct matrix {
  struct matrix_key keys[MATRIX_ROW_COUNT][MATRIX_COL_COUNT];
};

void matrix_init(struct matrix *m);
void matrix_scan(struct matrix *m, struct matrix_report *report);

#endif
