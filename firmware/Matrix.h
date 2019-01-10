#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

#include "MCP23S17.h"

class Matrix {
  public:
    enum class Row {
      N1, N2, N3, N4, N5, N6, N7, Count
    };

    enum class Col {
      A, B, C, D, E, F, G, H, I, J, K, L, Count
    };

    struct Report {
      uint16_t pressed[(int)Row::Count];
      uint16_t released[(int)Col::Count];
    };

    Matrix(void);
    void begin(void);
    void scan(Report *report);

  private:
    struct KeyState {
      bool pressed : 1;
      uint8_t pressTime : 7;
    };

    MCP mcp;
    KeyState keys[(int)Row::Count][(int)Col::Count];

    static const uint8_t rowPins[];
    static const uint8_t colPins[];
    static const uint8_t debounce_time = 5;
};

#endif
