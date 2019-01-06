#ifndef KEYMAP_H
#define KEYMAP_H

#include <stdint.h>

#include "Matrix.h"

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
    enum class Layer {
      Base,
      Sym,
      Count
    };

    enum class ModState {
      Off,
      StickLight,
      StickHeavy
    };

    enum class Key {
      A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,

      Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num0,

      Enter, Esc, BSpace, Tab, Space, Minus, Equal, LBrace, RBrace, BSlash, Tilde,
      Semicolon, SQuote, Grave, Comma, Period, Slash, Percent, At, LBrack, RBrack,
      Carrot, Pound, Dollar, LParen, RParen, Asterisk, Bang, Plus, Underscore,
      Ampersand, Pipe, Question,

      F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,

      PrintScr, ScrollLock, Pause, Home, PgUp, Del, End, PgDn, Right, Left, Down, Up,

      Ctrl, Shift, Alt,

      LayerSym,

      None
    };

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

    enum class ScancodeMod {
      None = 0,
      Ctrl = 1 << 0,
      Shift = 1 << 1,
      Alt = 1 << 2
    };


    Layer activeLayer;

    ModState mods;

    struct KeyInfo {
      Scancode scancode : 7;
      ScancodeMod mod : 3;
    };

    static const uint8_t scancodes[];
    static const KeyInfo scancodeMap[];
    static const Key layout[(int)Keymap::Layer::Count][(int)Matrix::Dim::Row][(int)Matrix::Dim::Col];
};

#endif
