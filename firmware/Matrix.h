#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>
#include "MCP23S17.h"

#define MATRIX_ROW_COUNT 7
#define MATRIX_COL_COUNT 15

class Matrix {
  public:

    struct report {
      uint16_t pressed[MATRIX_ROW_COUNT];
      uint16_t released[MATRIX_ROW_COUNT];
    };

    Matrix(void);
    void scan(Matrix::report *report);

  private:
    MCP mcp;
    struct key {
      uint8_t pressed : 1;
      uint8_t press_time : 7;
    };
    key keys[MATRIX_ROW_COUNT][MATRIX_COL_COUNT];
};

#endif
