#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "Matrix.h"
#include "KeyMap.h"

class Keyboard {
  public:
    Keyboard(void);
    void begin(void);
    void update(void);

  private:
    Matrix matrix;
    Keymap keymap;
    //Hid hid;
};


#endif
