#include "matrix.h"
#include "MCP23S17.h"

enum row_pin {
  ROW1 = 4,
  ROW2 = 3,
  ROW3 = 2,
  ROW4 = 16,
  ROW5 = 15,
  ROW6 = 7,
  ROW7 = 11
};

enum col_pin {
  COL_A = 1,
  COL_B = 2,
  COL_C = 3,
  COL_D = 4,
  COL_E = 5,
  COL_F = 6,
  COL_G = 7,
  COL_H = 8,
  COL_I = 9,
  COL_J = 10,
  COL_K = 11,
  COL_L = 12,
  COL_M = 13,
  COL_N = 14,
  COL_O = 15
};

const enum row_pin row_pins[MATRIX_ROW_NUM] = {
  ROW1,
  ROW2,
  ROW3,
  ROW4,
  ROW5,
  ROW6,
  ROW7
};


const enum col_pin col_pins[MATRIX_COL_NUM] = {
  COL_A,
  COL_B,
  COL_C,
  COL_D,
  COL_E,
  COL_F,
  COL_G,
  COL_H,
  COL_I,
  COL_J,
  COL_K,
  COL_L
};

const char debounce_time = 5;

MCP mcp(0, 27);

void matrix_init(struct matrix *m) {
  memset(&m->keys, 0, sizeof(m->keys));

  mcp.begin();

  for (unsigned char c = 0; c < MATRIX_COL_NUM; c++) {
      mcp.pinMode(col_pins[c], OUTPUT);
      mcp.digitalWrite(col_pins[c], HIGH);
  }

  for (unsigned char r = 0; r < MATRIX_ROW_NUM; r++) {
      pinMode(row_pins[r], INPUT_PULLUP);
      digitalWrite(row_pins[r], HIGH);
  }

}

void matrix_scan(struct matrix *m, struct matrix_report *r) {
  memset(r, 0, sizeof(struct matrix_report))

  unsigned char scan_time = millis();

  for (unsigned char c = 0; c < MATRIX_COL_NUM; c++) {            
  
    mcp.digitalWrite(col_pins[c], LOW);
  
    delayMicroseconds(30);
  
    for (unsigned char r = 0; r < MATRIX_ROW_NUM; r++) {
      unsigned char pressed = digitalRead(row_pins[r]) == LOW;

      struct matrix_key *key_old = &m->keys[r][c];
      struct matrix_key key_new = { .pressed = pressed; .press_time = scan_time }

      if (key_new->pressed && !key_old->pressed) {
        *key_old = key_new;
        r->pressed[r] |= 1 << c
        Serial.println(r);
        Serial.println(c);
      } else if (!pressed && key_old->pressed) {
        if (key_new->press_time - key_old->press_time > debounce_time) {
          key_old->pressed = 0;
          r->released[r] |= 1 << c
        }
      }
    }
  
    mcp.digitalWrite(col_pins[c], HIGH);
  }
}
