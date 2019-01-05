#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Matrix.h"
#include "KeyMap.h"

class Keyboard {
  public:
    Keyboard(void);
    void update(void);
    void begin(void);

  private:
    Matrix matrix;
    Keymap keymap;
    //Hid hid;
};


#endif
