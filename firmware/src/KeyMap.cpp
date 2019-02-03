#include "KeyMap.h"

#include <Arduino.h>

const Keymap::Key Keymap::layout[][(int)Matrix::Dim::Row][(int)Matrix::Dim::Col] = {
  [(int)Layer::Base] = {
    { Key::None, Key::Num9, Key::Num7, Key::Num5, Key::Num3, Key::Num1, Key::Num0, Key::Num2, Key::Num4, Key::Num6, Key::Num8, Key::None },
    { Key::None, Key::SQuote, Key::Comma, Key::Period, Key::P, Key::Y, Key::F, Key::G, Key::C, Key::R, Key::L, Key::None },
    { Key::None, Key::A, Key::O, Key::E, Key::U, Key::I, Key::D, Key::H, Key::T, Key::N, Key::S, Key::None },
    { Key::Shift, Key::Semicolon, Key::Q, Key::J, Key::K, Key::X, Key::B, Key::M, Key::W, Key::V, Key::Z, Key::Shift },
    { Key::None, Key::None, Key::Alt, Key::Sym, Key::None, Key::Ctrl, Key::Ctrl, Key::None, Key::Sym, Key::Alt, Key::None, Key::None },
    { Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::Space, Key::BSpace, Key::None, Key::None, Key::None, Key::None },
    { Key::None, Key::None, Key::None, Key::Enter, Key::Esc, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None }
  },
  [(int)Layer::Sym] = {
    { Key::None, Key::F9, Key::F7, Key::F5, Key::F3, Key::F1, Key::F10, Key::F2, Key::F4, Key::F6, Key::F8, Key::None },
    { Key::None, Key::Percent, Key::At, Key::BSlash, Key::LBrace, Key::LBrack, Key::RBrack, Key::RBrace, Key::Tilde, Key::Carrot, Key::Grave, Key::None },
    { Key::None, Key::Pound, Key::Dollar, Key::LParen, Key::Asterisk, Key::Bang, Key::Slash, Key::Underscore, Key::RParen, Key::Equal, Key::Plus, Key::None },
    { Key::None, Key::None, Key::None, Key::Ampersand, Key::Pipe, Key::None, Key::None, Key::Minus, Key::Question, Key::None, Key::None, Key::None },
    { Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None },
    { Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None },
    { Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None, Key::None }
  }
};

Keymap::Keymap(void) {
  memset(&keysPressed, 0, sizeof(keysPressed));
  memset(&matrixPressed, 0, sizeof(matrixPressed));

  for (int m = 0; m < (int)Mod::Count; m++) {
    modStates[m] = ModState::Off;
  }
}

Keymap::Key Keymap::resolveKey(
  const Matrix::Key k
) const {
  switch (modStates[(int)Mod::Sym]) {
    case ModState::Off:
      return layout[(int)Layer::Base][k.r][k.c];
    case ModState::StickLight:
    case ModState::StickHeavy:
      auto key = layout[(int)Layer::Sym][k.r][k.c];
      return key == Key::None ? layout[(int)Layer::Base][k.r][k.c] : key;
  }
}

Keymap::ModState Keymap::nextModState(Keymap::ModState modState) const {
  switch (modState) {
    case ModState::Off:
      return ModState::StickLight;
    case ModState::StickLight:
      return ModState::StickHeavy;
    case ModState::StickHeavy:
      return ModState::Off;
  }
}

bool Keymap::modActive(Keymap::Mod m) const {
  switch (modStates[(int)m]) {
    case ModState::Off:
      return false;
    case ModState::StickLight:
      return true;
    case ModState::StickHeavy:
      return true;
  }
}

Keymap::Mod Keymap::keyToMod(Keymap::Key k) const {
  switch (k) {
    case Key::Ctrl:
      return Mod::Ctrl;
    case Key::Alt:
      return Mod::Alt;
    case Key::Shift:
      return Mod::Shift;
    case Key::Sym:
      return Mod::Sym;
  }
}

void Keymap::update(
  const Matrix *matrix
) {
  auto oldKeysPressed = keysPressed;
  auto oldMatrixPressed = matrixPressed;

  bool nonModifierPressed = false;
  for (auto r = 0; r < (int)Matrix::Dim::Row; r++) {
    for (auto c = 0; c < (int)Matrix::Dim::Col; c++) {
      Matrix::Key matrixKey = { .r = r, .c = c };
      auto key = resolveKey(matrixKey);
      auto wasPressed = oldMatrixPressed[r][c];
      bool isPressed = matrix->pressed(matrixKey);
      matrixPressed[r][c] = isPressed;

      switch (key) {
        case Key::None: break;
        case Key::Ctrl:
        case Key::Alt:
        case Key::Shift:
        case Key::Sym: {
          auto m = keyToMod(key);
          if (isPressed && !wasPressed) {
            modStates[(int)m] = nextModState(modStates[(int)m]);
          }
          keysPressed[(int)key] = modActive(m);
          break;
        }
        default:
          nonModifierPressed = nonModifierPressed || isPressed;
          keysPressed[(int)key] = isPressed;
          break;
      }
    }
  }

  if (nonModifierPressed) {
    for (int m = 0; m < (int)Mod::Count; m++) {
      if (modStates[m] == ModState::StickLight) {
        modStates[m] = ModState::Off;
      }
    }
  }
}

bool Keymap::pressed(const Keymap::Key k) const {
  return keysPressed[(int)k];
}
