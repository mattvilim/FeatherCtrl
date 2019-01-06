#include "KeyMap.h"

const uint8_t Keymap::scancodes[] = {
  [(int)Scancode::A] = 0x4,
  [(int)Scancode::B] = 0x5,
  [(int)Scancode::C] = 0x6,
  [(int)Scancode::D] = 0x7,
  [(int)Scancode::E] = 0x8,
  [(int)Scancode::F] = 0x9,
  [(int)Scancode::G] = 0xa,
  [(int)Scancode::H] = 0xb,
  [(int)Scancode::I] = 0xc,
  [(int)Scancode::J] = 0xd,
  [(int)Scancode::K] = 0xe,
  [(int)Scancode::L] = 0xf,
  [(int)Scancode::M] = 0x10,
  [(int)Scancode::N] = 0x11,
  [(int)Scancode::O] = 0x12,
  [(int)Scancode::P] = 0x13,
  [(int)Scancode::Q] = 0x14,
  [(int)Scancode::R] = 0x15,
  [(int)Scancode::S] = 0x16,
  [(int)Scancode::T] = 0x17,
  [(int)Scancode::U] = 0x18,
  [(int)Scancode::V] = 0x19,
  [(int)Scancode::W] = 0x1a,
  [(int)Scancode::X] = 0x1b,
  [(int)Scancode::Y] = 0x1c,
  [(int)Scancode::Z] = 0x1d,

  [(int)Scancode::Num1] = 0x1e,
  [(int)Scancode::Num2] = 0x1f,
  [(int)Scancode::Num3] = 0x20,
  [(int)Scancode::Num4] = 0x21,
  [(int)Scancode::Num5] = 0x22,
  [(int)Scancode::Num6] = 0x23,
  [(int)Scancode::Num7] = 0x24,
  [(int)Scancode::Num8] = 0x25,
  [(int)Scancode::Num9] = 0x26,
  [(int)Scancode::Num0] = 0x27,

  [(int)Scancode::Enter] = 0x28,
  [(int)Scancode::Esc] = 0x29,
  [(int)Scancode::BSpace] = 0x2a,
  [(int)Scancode::Tab] = 0x2b,
  [(int)Scancode::Space] = 0x2c,
  [(int)Scancode::Minus] = 0x2d,
  [(int)Scancode::Equal] = 0x2e,
  [(int)Scancode::LBrace] = 0x2f,
  [(int)Scancode::RBrace] = 0x30,
  [(int)Scancode::BSlash] = 0x31,
  [(int)Scancode::Tilde] = 0x32,
  [(int)Scancode::Semicolon] = 0x33,
  [(int)Scancode::SQuote] = 0x34,
  [(int)Scancode::Grave] = 0x35,
  [(int)Scancode::Comma] = 0x36,
  [(int)Scancode::Period] = 0x37,
  [(int)Scancode::Slash] = 0x38,

  [(int)Scancode::F1] = 0x3a,
  [(int)Scancode::F2] = 0x3b,
  [(int)Scancode::F3] = 0x3c,
  [(int)Scancode::F4] = 0x3d,
  [(int)Scancode::F5] = 0x3e,
  [(int)Scancode::F6] = 0x3f,
  [(int)Scancode::F7] = 0x40,
  [(int)Scancode::F8] = 0x41,
  [(int)Scancode::F9] = 0x42,
  [(int)Scancode::F10] = 0x43,
  [(int)Scancode::F11] = 0x44,
  [(int)Scancode::F12] = 0x45,
  [(int)Scancode::Home] = 0x4a,
  [(int)Scancode::PgUp] = 0x4b,
  [(int)Scancode::Del] = 0x4c,
  [(int)Scancode::End] = 0x4d,
  [(int)Scancode::PgDn] = 0x4e,
  [(int)Scancode::Right] = 0x50,
  [(int)Scancode::Left] = 0x50,
  [(int)Scancode::Down] = 0x51,
  [(int)Scancode::Up] = 0x52
};

const Keymap::KeyInfo Keymap::scancodeMap[] = {
  [(int)Key::A] = { .scancode = Scancode::A, .mod = Mod::None },
  [(int)Key::B] = { .scancode = Scancode::B, .mod = Mod::None },
  [(int)Key::C] = { .scancode = Scancode::C, .mod = Mod::None },
  [(int)Key::D] = { .scancode = Scancode::D, .mod = Mod::None },
  [(int)Key::E] = { .scancode = Scancode::E, .mod = Mod::None },
  [(int)Key::F] = { .scancode = Scancode::F, .mod = Mod::None },
  [(int)Key::G] = { .scancode = Scancode::G, .mod = Mod::None },
  [(int)Key::H] = { .scancode = Scancode::H, .mod = Mod::None },
  [(int)Key::I] = { .scancode = Scancode::I, .mod = Mod::None },
  [(int)Key::J] = { .scancode = Scancode::J, .mod = Mod::None },
  [(int)Key::K] = { .scancode = Scancode::K, .mod = Mod::None },
  [(int)Key::L] = { .scancode = Scancode::L, .mod = Mod::None },
  [(int)Key::M] = { .scancode = Scancode::M, .mod = Mod::None },
  [(int)Key::N] = { .scancode = Scancode::N, .mod = Mod::None },
  [(int)Key::O] = { .scancode = Scancode::O, .mod = Mod::None },
  [(int)Key::P] = { .scancode = Scancode::P, .mod = Mod::None },
  [(int)Key::Q] = { .scancode = Scancode::Q, .mod = Mod::None },
  [(int)Key::R] = { .scancode = Scancode::R, .mod = Mod::None },
  [(int)Key::S] = { .scancode = Scancode::S, .mod = Mod::None },
  [(int)Key::T] = { .scancode = Scancode::T, .mod = Mod::None },
  [(int)Key::U] = { .scancode = Scancode::U, .mod = Mod::None },
  [(int)Key::V] = { .scancode = Scancode::V, .mod = Mod::None },
  [(int)Key::W] = { .scancode = Scancode::W, .mod = Mod::None },
  [(int)Key::X] = { .scancode = Scancode::X, .mod = Mod::None },
  [(int)Key::Y] = { .scancode = Scancode::Y, .mod = Mod::None },
  [(int)Key::Z] = { .scancode = Scancode::Z, .mod = Mod::None },

  [(int)Key::Num1] = { .scancode = Scancode::Num1, .mod = Mod::None },
  [(int)Key::Num2] = { .scancode = Scancode::Num2, .mod = Mod::None },
  [(int)Key::Num3] = { .scancode = Scancode::Num3, .mod = Mod::None },
  [(int)Key::Num4] = { .scancode = Scancode::Num4, .mod = Mod::None },
  [(int)Key::Num5] = { .scancode = Scancode::Num5, .mod = Mod::None },
  [(int)Key::Num6] = { .scancode = Scancode::Num6, .mod = Mod::None },
  [(int)Key::Num7] = { .scancode = Scancode::Num7, .mod = Mod::None },
  [(int)Key::Num8] = { .scancode = Scancode::Num8, .mod = Mod::None },
  [(int)Key::Num9] = { .scancode = Scancode::Num9, .mod = Mod::None },
  [(int)Key::Num0] = { .scancode = Scancode::Num0, .mod = Mod::None },

  [(int)Key::Enter] = { .scancode = Scancode::Enter, .mod = Mod::None },
  [(int)Key::Esc] = { .scancode = Scancode::Esc, .mod = Mod::None },
  [(int)Key::BSpace] = { .scancode = Scancode::BSpace, .mod = Mod::None },
  [(int)Key::Tab] = { .scancode = Scancode::Tab, .mod = Mod::None },
  [(int)Key::Space] = { .scancode = Scancode::Space, .mod = Mod::None },
  [(int)Key::Minus] = { .scancode = Scancode::Minus, .mod = Mod::None },
  [(int)Key::Equal] = { .scancode = Scancode::Equal, .mod = Mod::None },
  [(int)Key::LBrace] = { .scancode = Scancode::LBrace, .mod = Mod::None },
  [(int)Key::RBrace] = { .scancode = Scancode::RBrace, .mod = Mod::None },
  [(int)Key::BSlash] = { .scancode = Scancode::BSlash, .mod = Mod::None },
  [(int)Key::Tilde] = { .scancode = Scancode::Tilde, .mod = Mod::None },
  [(int)Key::Semicolon] = { .scancode = Scancode::Semicolon, .mod = Mod::None },
  [(int)Key::SQuote] = { .scancode = Scancode::SQuote, .mod = Mod::None },
  [(int)Key::Grave] = { .scancode = Scancode::Grave, .mod = Mod::None },
  [(int)Key::Comma] = { .scancode = Scancode::Comma, .mod = Mod::None },
  [(int)Key::Period] = { .scancode = Scancode::Period, .mod = Mod::None },
  [(int)Key::Slash] = { .scancode = Scancode::Slash, .mod = Mod::None },
  [(int)Key::Percent] = { .scancode = Scancode::Num5, .mod = Mod::Shift },
  [(int)Key::At] = { .scancode = Scancode::Num2, .mod = Mod::Shift },
  [(int)Key::LBrack] = { .scancode = Scancode::LBrace, .mod = Mod::Shift },
  [(int)Key::RBrack] = { .scancode = Scancode::RBrace, .mod = Mod::Shift },
  [(int)Key::Carrot] = { .scancode = Scancode::Num6, .mod = Mod::Shift },
  [(int)Key::Pound] = { .scancode = Scancode::Num3, .mod = Mod::Shift },
  [(int)Key::Dollar] = { .scancode = Scancode::Num4, .mod = Mod::Shift },
  [(int)Key::LParen] = { .scancode = Scancode::Num9, .mod = Mod::Shift },
  [(int)Key::RParen] = { .scancode = Scancode::Num0, .mod = Mod::Shift },
  [(int)Key::Asterisk] = { .scancode = Scancode::Num8, .mod = Mod::Shift },
  [(int)Key::Bang] = { .scancode = Scancode::Num1, .mod = Mod::Shift },
  [(int)Key::Plus] = { .scancode = Scancode::Equal, .mod = Mod::Shift },
  [(int)Key::Underscore] = { .scancode = Scancode::Minus, .mod = Mod::Shift },
  [(int)Key::Ampersand] = { .scancode = Scancode::Num7, .mod = Mod::Shift },
  [(int)Key::Pipe] = { .scancode = Scancode::BSlash, .mod = Mod::Shift },
  [(int)Key::Question] = { .scancode = Scancode::Slash, .mod = Mod::Shift },

  [(int)Key::F1] = { .scancode = Scancode::F1, .mod = Mod::None },
  [(int)Key::F2] = { .scancode = Scancode::F2, .mod = Mod::None },
  [(int)Key::F3] = { .scancode = Scancode::F3, .mod = Mod::None },
  [(int)Key::F4] = { .scancode = Scancode::F4, .mod = Mod::None },
  [(int)Key::F5] = { .scancode = Scancode::F5, .mod = Mod::None },
  [(int)Key::F6] = { .scancode = Scancode::F6, .mod = Mod::None },
  [(int)Key::F7] = { .scancode = Scancode::F7, .mod = Mod::None },
  [(int)Key::F8] = { .scancode = Scancode::F8, .mod = Mod::None },
  [(int)Key::F9] = { .scancode = Scancode::F9, .mod = Mod::None },
  [(int)Key::F10] = { .scancode = Scancode::F10, .mod = Mod::None },
  [(int)Key::F11] = { .scancode = Scancode::F11, .mod = Mod::None },
  [(int)Key::F12] = { .scancode = Scancode::F12, .mod = Mod::None },
  [(int)Key::PrintScr] = { .scancode = Scancode::None, .mod = Mod::None },
  [(int)Key::ScrollLock] = { .scancode = Scancode::None, .mod = Mod::None },
  [(int)Key::Pause] = { .scancode = Scancode::None, .mod = Mod::None },
  [(int)Key::Home] = { .scancode = Scancode::Home, .mod = Mod::None },
  [(int)Key::PgUp] = { .scancode = Scancode::PgUp, .mod = Mod::None },
  [(int)Key::Del] = { .scancode = Scancode::Del, .mod = Mod::None },
  [(int)Key::End] = { .scancode = Scancode::End, .mod = Mod::None },
  [(int)Key::PgDn] = { .scancode = Scancode::PgDn, .mod = Mod::None },
  [(int)Key::Right] = { .scancode = Scancode::Right, .mod = Mod::None },
  [(int)Key::Left] = { .scancode = Scancode::Left, .mod = Mod::None },
  [(int)Key::Down] = { .scancode = Scancode::Down, .mod = Mod::None },
  [(int)Key::Up] = { .scancode = Scancode::Up, .mod = Mod::None }
};

const uint8_t Keymap::modMap[] = {
  [(int)Mod::Ctrl] = 1 << 0,
  [(int)Mod::Shift] = 1 << 1,
  [(int)Mod::Alt] = 1 << 2
};

const Keymap::Key Keymap::layout[][(int)Matrix::Dim::Row][(int)Matrix::Dim::Col] = {
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
  activeLayer = Keymap::Layer::Base;

  for (int m = 0; m < (int)Mod::Count; m++) {
    mods[m] = ModState::Off;
  }
}

void Keymap::update(
  const Matrix::Report *mr,
  Keymap::Report *kr
) {
  for (auto r = 0; r < (int)Matrix::Dim::Row; r++) {
    for (auto c = 0; c < (int)Matrix::Dim::Col; c++) {
      auto mask = 1 << c;
      bool pressed = mr->pressed[r] & mask;
      bool released = mr->released[r] & mask;

      auto k = layout[(int)activeLayer][r][c];
      switch (k) {
        case Key::None: break;
        case Key::LayerSym:
          break;
        case Key::Ctrl:
          break;
        case Key::Alt:
          break;
        case Key::Shift:
          break;
        default:
          auto info = &scancodeMap[(int)k];
          auto scan = (int)info->scancode;
          kr->scancodes[scan / 8] |= 1 << (scan % 8);
          break;
      };
    }
  }
}
