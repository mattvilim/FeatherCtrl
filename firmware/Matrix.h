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

    struct Key {
      uint8_t r;
      uint8_t c;
    };

    Matrix(void);
    void begin(void);
    void scan(void);
    bool pressed(const Key k) const;

  private:
    struct KeyState {
      uint8_t pressTime;
      bool pressed;
    };

    MCP mcp;
    KeyState keys[(int)Row::Count][(int)Col::Count];

    static const uint8_t rowPins[];
    static const uint8_t colPins[];
    static const uint8_t debounceTime = 5;
};

#endif
