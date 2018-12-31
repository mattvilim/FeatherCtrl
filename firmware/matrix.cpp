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

const char debounce_time = 7;

MCP mcp(0, 27);

void matrix_init(struct matrix *m) {
  memset(&m->keys, 0, sizeof(m->keys));

  mcp.begin();

  for (unsigned char r = 0; r < MATRIX_ROW_NUM; r++) {
      mcp.pinMode(row_pins[r], OUTPUT);
      mcp.digitalWrite(row_pins[r], HIGH);
  }

  for (unsigned char c = 0; c < MATRIX_COL_NUM; c++) {
      pinMode(col_pins[c], INPUT_PULLUP);
      digitalWrite(col_pins[c], HIGH);
  }

}

void matrix_scan(struct matrix *m) {
  unsigned char scan_time = millis();

  for (unsigned char r = 0; r < MATRIX_ROW_NUM; r++) {
  
    mcp.digitalWrite(row_pins[r], LOW);                  
  
    delayMicroseconds(30);
  
    for (unsigned char c = 0; c < MATRIX_COL_NUM; c++) {            
      unsigned char pressed = digitalRead(col_pins[c]) == LOW;

      struct matrix_key *key = &m->keys[r][c];

      if (pressed && !key->pressed) {
        key->pressed = true;
        key->press_time = scan_time;
        Serial.print("test");
      } else if (!pressed && key->pressed) {
        if (scan_time - key->press_time > debounce_time) {
          key->pressed = false;
        }
      }
    }
  
    mcp.digitalWrite(row_pins[r], HIGH);
  }
}

