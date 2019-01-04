#include "KeyMap.h"

const enum class Key layerBase[Matrix::Rows][Matrix::Cols] = {
  { Key::None,
    Key::9,
    Key::7,
    Key::5,
    Key::3,
    Key::1,
    Key::0,
    Key::2,
    Key::4,
    Key::6,
    Key::8,
    Key::None
  },
  { Key::None,
    Key::SQuote,
    Key::Comma,
    Key::Period,
    Key::P,
    Key::Y,
    Key::F,
    Key::G,
    Key::C,
    Key::R,
    Key::L,
    Key::None
  },
  { Key::None,
    Key::A,
    Key::O,
    Key::E,
    Key::U,
    Key::I,
    Key::D,
    Key::H,
    Key::T,
    Key::N,
    Key::S,
    Key::None
  },
  { Key::None,
    Key::Semicolon,
    Key::Q,
    Key::J,
    Key::K,
    Key::X,
    Key::B,
    Key::M,
    Key::W,
    Key::V,
    Key::Z,
    Key::None
  },
  { Key::None,
    Key::None,
    Key::Alt,
    Key::LayerSym,
    Key::None,
    Key::Ctrl,
    Key::Ctrl,
    Key::None,
    Key::LayerSym,
    Key::Alt,
    Key::None,
    Key::None
  },
  { Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::Space,
    Key::BSpace,
    Key::None,
    Key::None,
    Key::None,
    Key::None
  },
  { Key::None,
    Key::None,
    Key::None,
    Key::Enter,
    Key::Esc,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None
  }
};

const enum class Key layerSym[Matrix::Rows][Matrix::Cols] = {
  { Key::None,
    Key::F9,
    Key::F7,
    Key::F5,
    Key::F3,
    Key::F1,
    Key::F10,
    Key::F2,
    Key::F4,
    Key::F6,
    Key::F8,
    Key::None
  },
  { Key::None,
    Key::Percent,
    Key::At,
    Key::BSlash,
    Key::LBrace,
    Key::LBrack,
    Key::RBrack,
    Key::RBrace,
    Key::Tilde,
    Key::Carrot,
    Key::Grave,
    Key::None
  },
  { Key::None,
    Key::Pound,
    Key::Dollar,
    Key::LParen,
    Key::Asterisk,
    Key::Bang,
    Key::Slash,
    Key::Underscore,
    Key::RParen,
    Key::Equal,
    Key::Plus,
    Key::None
  },
  { Key::None,
    Key::None,
    Key::None,
    Key::Ampersand,
    Key::Pipe,
    Key::None,
    Key::None,
    Key::MINUS,
    Key::Question,
    Key::None,
    Key::None,
    Key::None
  },
  { Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None
  },
  { Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None
  },
  { Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None,
    Key::None
  }
};

const enum class Key layout[Layer::Count][Matrix::Rows][Matrix::Cols] = {
  [Layer::Base] = layerBase,
  [Layer::Sym] = layerSym
}

Keymap::Keymap(void) {
  activeLayer = Layer::Base;
  shiftStuck = false;
  altStuck = false;
  ctrlStuck = false;
  layerSymStuck = false;
}

void Keymap::update(
  const Matrix::report *mr,
  struct scancode_report *sr
) {
  for (unsigned char r = 0; r < Matrix::Rows; r++) {
    for (unsigned char c = 0; c < Matrix::Cols; c++) {
      uint16_t mask = 1 << r;
      bool pressed = mr->pressed[r] & mask;
      bool released = mr->released[r] & mask;
    }
  }
}

