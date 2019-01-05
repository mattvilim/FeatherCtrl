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
    struct Report {
      uint16_t pressed[(int)Dim::Row];
      uint16_t released[(int)Dim::Row];
    };

    Matrix(void);
    void begin(void);
    void scan(Report *report);

  private:
    MCP mcp;
    struct KeyState {
      bool pressed : 1;
      uint8_t pressTime : 7;
    };
    KeyState keys[(int)Dim::Row][(int)Dim::Col];
};

#endif
