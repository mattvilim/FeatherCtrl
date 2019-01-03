#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>
#include "MCP23S17.h"

#define MATRIX_ROW_COUNT 7
#define MATRIX_COL_COUNT 15

struct matrix_report {
  uint16_t pressed[MATRIX_ROW_COUNT];
  uint16_t released[MATRIX_ROW_COUNT];
};

class Matrix {
  public:
    Matrix(void);
    void scan(struct matrix_report *report);

  private:
    MCP mcp;
    struct matrix_key {
      uint8_t pressed : 1;
      uint8_t press_time : 7;
    };
    struct matrix_key keys[MATRIX_ROW_COUNT][MATRIX_COL_COUNT];
};

#endif
