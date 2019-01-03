#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

#include "MCP23S17.h"

class Matrix {
  public:
    enum {
      Rows = 7,
      Cols = 15
    };
    struct report {
      uint16_t pressed[Rows];
      uint16_t released[Cols];
    };

    Matrix(void);
    void scan(report *report);

  private:
    MCP mcp;
    struct key {
      uint8_t pressed : 1;
      uint8_t press_time : 7;
    };
    key keys[Rows][Cols];
};

#endif
