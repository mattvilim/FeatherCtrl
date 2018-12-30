#include "matrix.h"

const enum rowPin {
  ROW1 = 4,
  ROW2 = 3,
  ROW3 = 2,
  ROW4 = 16,
  ROW5 = 15,
  ROW6 = 7,
  ROW7 = 11
};

const enum colPin {
  COL_A = 1
  COL_B = 2
  COL_C = 3
  COL_D = 4
  COL_E = 5
  COL_F = 6
  COL_G = 7
  COL_H = 8
  COL_I = 9
  COL_J = 10
  COL_K = 11
  COL_L = 12
  COL_M = 13
  COL_N = 14
  COL_O = 15
};

const enum rowPin rowPins[] = {
  ROW1,
  ROW2,
  ROW3,
  ROW4,
  ROW5,
  ROW6,
  ROW7
};


const enum colPin colPins[] = {
  COL_A,
  COL_B,
  COL_C,
  COL_D,
  COL_E,
  COL_F,
  COL_G,
  COL_H,
  COL_I,
  COL_J,
  COL_K,
  COL_L
};

const char rowCount = sizeof(rowPins) / sizeof(rowPins[0])
const char colCount = sizeof(colPins) / sizeof(colPins[0])
