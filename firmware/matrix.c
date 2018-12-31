#include "matrix.h"

enum matrix_row_pin {
  MATRIX_ROW1 = 4,
  MATRIX_ROW2 = 3,
  MATRIX_ROW3 = 2,
  MATRIX_ROW4 = 16,
  MATRIX_ROW5 = 15,
  MATRIX_ROW6 = 7,
  MATRIX_ROW7 = 11
};

enum matrix_col_pin {
  MATRIX_COL_A = 1
  MATRIX_COL_B = 2
  MATRIX_COL_C = 3
  MATRIX_COL_D = 4
  MATRIX_COL_E = 5
  MATRIX_COL_F = 6
  MATRIX_COL_G = 7
  MATRIX_COL_H = 8
  MATRIX_COL_I = 9
  MATRIX_COL_J = 10
  MATRIX_COL_K = 11
  MATRIX_COL_L = 12
  MATRIX_COL_M = 13
  MATRIX_COL_N = 14
  MATRIX_COL_O = 15
};

const enum matrix_row_pin matrix_row_pins[] = {
  MATRIX_ROW1,
  MATRIX_ROW2,
  MATRIX_ROW3,
  MATRIX_ROW4,
  MATRIX_ROW5,
  MATRIX_ROW6,
  MATRIX_ROW7
};


const enum matrix_col_pin matrix_col_pins[] = {
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
  MATRIX_COL_L
};

const char matrix_row_num = sizeof(matrix_row_pins) / sizeof(matrix_row_pins[0])
const char matrix_col_num = sizeof(matrix_col_pins) / sizeof(matrix_col_pins[0])

void matrix_init(struct matrix *m) {
}

void matrix_scan(struct matrix *m) {
}
