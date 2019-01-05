#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

#include "MCP23S17.h"

class Matrix {
  public:
    enum class Dim {
      Row = 7,
      Col = 12
    };
    struct report {
      uint16_t pressed[(int)Dim::Row];
      uint16_t released[(int)Dim::Row];
    };

    Matrix(void);
    void scan(report *report);

  private:
    MCP mcp;
    struct key {
      uint8_t pressed : 1;
      uint8_t press_time : 7;
    };
    key keys[(int)Dim::Row][(int)Dim::Col];
};

#endif
