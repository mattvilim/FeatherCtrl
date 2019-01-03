#include "keymap.h"

#include "matrix.h"

const enum keymap_key layer_base[MATRIX_ROW_COUNT][MATRIX_COL_COUNT] = {
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_9,
      KEYMAP_KEY_7,
      KEYMAP_KEY_5,
      KEYMAP_KEY_3,
      KEYMAP_KEY_1,
      KEYMAP_KEY_0,
      KEYMAP_KEY_2,
      KEYMAP_KEY_4,
      KEYMAP_KEY_6,
      KEYMAP_KEY_8,
      KEYMAP_KEY_NONE
    }
  },
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_SQUOTE,
      KEYMAP_KEY_COMMA,
      KEYMAP_KEY_PERIOD,
      KEYMAP_KEY_P,
      KEYMAP_KEY_Y,
      KEYMAP_KEY_F,
      KEYMAP_KEY_G,
      KEYMAP_KEY_C,
      KEYMAP_KEY_R,
      KEYMAP_KEY_L,
      KEYMAP_KEY_NONE
    }
  },
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_A,
      KEYMAP_KEY_O,
      KEYMAP_KEY_E,
      KEYMAP_KEY_U,
      KEYMAP_KEY_I,
      KEYMAP_KEY_D,
      KEYMAP_KEY_H,
      KEYMAP_KEY_T,
      KEYMAP_KEY_N,
      KEYMAP_KEY_S,
      KEYMAP_KEY_NONE
    }
  },
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_SEMICOLON,
      KEYMAP_KEY_Q,
      KEYMAP_KEY_J,
      KEYMAP_KEY_K,
      KEYMAP_KEY_X,
      KEYMAP_KEY_B,
      KEYMAP_KEY_M,
      KEYMAP_KEY_W,
      KEYMAP_KEY_V,
      KEYMAP_KEY_Z,
      KEYMAP_KEY_NONE
    }
  },
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_ALT,
      KEYMAP_KEY_LAYER_SYM,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_CTRL,
      KEYMAP_KEY_CTRL,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_LAYER_SYM,
      KEYMAP_KEY_ALT,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE
    }
  },
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_SPACE,
      KEYMAP_KEY_BSPACE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE
    }
  },
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_ENTER,
      KEYMAP_KEY_ESC,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE
    }
  }
};

const enum keymap_key layer_sym[MATRIX_ROW_COUNT][MATRIX_COL_COUNT] = {
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_F9,
      KEYMAP_KEY_F7,
      KEYMAP_KEY_F5,
      KEYMAP_KEY_F3,
      KEYMAP_KEY_F1,
      KEYMAP_KEY_F0,
      KEYMAP_KEY_F2,
      KEYMAP_KEY_F4,
      KEYMAP_KEY_F6,
      KEYMAP_KEY_F8,
      KEYMAP_KEY_NONE
    }
  },
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_PERCENT,
      KEYMAP_KEY_AT,
      KEYMAP_KEY_BSLASH,
      KEYMAP_KEY_LBRACE,
      KEYMAP_KEY_LBRACK,
      KEYMAP_KEY_RBRACK,
      KEYMAP_KEY_RBRACE,
      KEYMAP_KEY_TILDE,
      KEYMAP_KEY_CARROT,
      KEYMAP_KEY_GRAVE,
      KEYMAP_KEY_NONE
    }
  },
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_POUND,
      KEYMAP_KEY_DOLLAR,
      KEYMAP_KEY_LPAREN,
      KEYMAP_KEY_ASTERISK,
      KEYMAP_KEY_BANG,
      KEYMAP_KEY_SLASH,
      KEYMAP_KEY_UNDERSCORE,
      KEYMAP_KEY_RPAREN,
      KEYMAP_KEY_EQUAL,
      KEYMAP_KEY_PLUS,
      KEYMAP_KEY_NONE
    }
  },
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_AMPERSAND,
      KEYMAP_KEY_PIPE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_MINUS,
      KEYMAP_KEY_QUESTION,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE
    }
  },
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE
    }
  },
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE
    }
  },
  { { KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE,
      KEYMAP_KEY_NONE
    }
  }
};

const key_config layout[KEYMAP_LAYER_COUNT][MATRIX_ROW_COUNT][MATRIX_COL_COUNT] = {
  [KEYMAP_LAYER_BASE] = layer_base,
  [KEYMAP_LAYER_SYM] = layer_sym
}

void keymap_init(struct keymap *k) {
  k->active_layer = KEYMAP_LAYER_BASE;
}

void keymap_update(
  struct keymap *k,
  const struct matrix_report *mr,
  struct scancode_report *sr
) {
  for (unsigned char r = 0; r < MATRIX_ROW_COUNT; r++) {
    for (unsigned char c = 0; c < MATRIX_COL_COUNT; c++) {
      uint16_t mask = 1 << r;
      bool pressed = k->pressed[r] & mask;
      bool released = k->released[r] & mask;
    }
  }
}

