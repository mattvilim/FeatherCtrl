#ifndef KEYMAP_H
#define KEYMAP_H

#include <stdint.h>

#include "Matrix.h"

enum class Layer;

class Keymap {
  public:
    struct Report {
      uint16_t scancodes[6];
      uint8_t modifiers;
    };

    Keymap(void);
    void update(
      const Matrix::Report *mr,
      Report *kr
    );

  private:
    Layer activeLayer;

    bool shiftStuck : 1;
    bool altStuck : 1;
    bool ctrlStuck : 1;
    bool layerSymStuck : 1;
};

#endif
