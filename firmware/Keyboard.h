#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "matrix.h"
#include "keymap.h"
#include "hid.h"

class Keyboard {
  public:
    void loop(void);

  private:
    Matrix matrix;
    Keymap keymap;
    //Hid hid;
};


#endif
