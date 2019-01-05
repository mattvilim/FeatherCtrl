#include "KeyMap.h"

enum class Key layout[(int)Layer::Count][(int)Matrix::Dim::Row][(int)Matrix::Dim::Col] = {
  [(int)Layer::Base] = {
    { Key::None, Key::Num9, Key::Num7, Key::Num5, Key::Num3, Key::Num1, Key::Num0, Key::Num2, Key::Num4, Key::Num6, Key::Num8, Key::None },
    { Key::None, Key::SQuote, Key::Comma, Key::Period, Key::P, Key::Y, Key::F, Key::G, Key::C, Key::R, Key::L, Key::None },
    { Key::None, Key::A, Key::O, Key::E, Key::U, Key::I, Key::D, Key::H, Key::T, Key::N, Key::S, Key::None },
    { Key::None, Key::Semicolon, Key::Q, Key::J, Key::K, Key::X, Key::B, Key::M, Key::W, Key::V, Key::Z, Key::None },
    { Key::None, Key::None, Key::Alt, Key::LayerSym, Key::None, Key::Ctrl, Key::Ctrl, Key::None, Key::LayerSym, Key::Alt, Key::None, Key::None },
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
  activeLayer = Layer::Base;
  shiftStuck = false;
  altStuck = false;
  ctrlStuck = false;
  layerSymStuck = false;
}

void Keymap::update(
  const Matrix::Report *mr,
  Keymap::Report *kr
) {
  for (auto r = 0; r < (int)Matrix::Dim::Row; r++) {
    for (auto c = 0; c < (int)Matrix::Dim::Col; c++) {
      uint16_t mask = 1 << c;
      bool pressed = mr->pressed[r] & mask;
      bool released = mr->released[r] & mask;
    }
  }
}
