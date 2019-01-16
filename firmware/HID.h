#ifndef HID_H
#define HID_H

#include <bluefruit.h>

#include "KeyMap.h"

class HID {
  public:
    HID(void);
    void begin(void);
    void sendKeys(void);
  private:

    enum class Scancode {
      A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

      Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num0,

      Enter, Esc, BSpace, Tab, Space, Minus, Equal, LBrace, RBrace, BSlash,
      Tilde, Semicolon, SQuote, Grave, Comma, Period, Slash,

      F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,

      Home, PgUp, Del, End, PgDn, Right, Left, Down, Up,

      Count,
      None
    };

    enum class Mod {
      Ctrl,
      Shift,
      Alt,
      Count,
      None
    };

    struct KeyInfo {
      Scancode scancode : 7;
      Mod mod : 3;
    };

    BLEHidAdafruit bleHID;
    BLEDis bleDIS;

    static const uint8_t scancodes[];
    static const KeyInfo scancodeMap[];
    static const uint8_t modMap[];
};


#endif
