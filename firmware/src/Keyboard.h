#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Matrix.h"
#include "KeyMap.h"
#include "HID.h"

class Keyboard {
  public:
    Keyboard(void);
    void begin(void);
    void update(void);

  private:
    Matrix matrix;
    Keymap keymap;
    HID hid;
};


#endif
