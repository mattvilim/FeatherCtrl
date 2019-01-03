#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Matrix.h"
#include "KeyMap.h"
#include "HID.h"

class Keyboard {
  public:
    void update(void);

  private:
    Matrix matrix;
    Keymap keymap;
    //Hid hid;
};


#endif
