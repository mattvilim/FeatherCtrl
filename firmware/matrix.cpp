#include "matrix.h"
#include "MCP23S17.h"


const unsigned char row_pins[] = {
  [MATRIX_ROW1] = 4,
  [MATRIX_ROW2] = 3,
  [MATRIX_ROW3] = 2,
  [MATRIX_ROW4] = 16,
  [MATRIX_ROW5] = 15,
  [MATRIX_ROW6] = 7,
  [MATRIX_ROW7] = 11
};

const unsigned char col_pins[] = {
  [MATRIX_COL_A] = 1,
  [MATRIX_COL_B] = 2,
  [MATRIX_COL_C] = 3,
  [MATRIX_COL_D] = 4,
  [MATRIX_COL_E] = 5,
  [MATRIX_COL_F] = 6,
  [MATRIX_COL_G] = 7,
  [MATRIX_COL_H] = 8,
  [MATRIX_COL_I] = 9,
  [MATRIX_COL_J] = 10,
  [MATRIX_COL_K] = 11,
  [MATRIX_COL_L] = 12,
  [MATRIX_COL_M] = 13,
  [MATRIX_COL_N] = 14,
  [MATRIX_COL_O] = 15
};

const char debounce_time = 5;

MCP mcp(0, 27);

void matrix_init(struct matrix *m) {
  memset(&m->keys, 0, sizeof(m->keys));

  mcp.begin();

  for (unsigned char c = 0; c < MATRIX_COL_COUNT; c++) {
      mcp.pinMode(col_pins[c], OUTPUT);
      mcp.digitalWrite(col_pins[c], HIGH);
  }

  for (unsigned char r = 0; r < MATRIX_ROW_COUNT; r++) {
      pinMode(row_pins[r], INPUT_PULLUP);
      digitalWrite(row_pins[r], HIGH);
  }

}

void matrix_scan(struct matrix *m, struct matrix_report *report) {
  memset(report, 0, sizeof(struct matrix_report));

  unsigned char scan_time = millis();

  for (unsigned char c = 0; c < MATRIX_COL_COUNT; c++) {            
  
    mcp.digitalWrite(col_pins[c], LOW);
  
    delayMicroseconds(30);
  
    for (unsigned char r = 0; r < MATRIX_ROW_COUNT; r++) {
      unsigned char pressed = digitalRead(row_pins[r]) == LOW;

      struct matrix_key *key_old = &m->keys[r][c];
      struct matrix_key key_new = { .pressed = pressed, .press_time = scan_time };

      if (key_new.pressed && !key_old->pressed) {
        *key_old = key_new;
        report->pressed[r] |= 1 << c;
        Serial.println(r);
        Serial.println(c);
      } else if (!pressed && key_old->pressed) {
        if (key_new.press_time - key_old->press_time > debounce_time) {
          key_old->pressed = 0;
          report->released[r] |= 1 << c;
        }
      }
    }
  
    mcp.digitalWrite(col_pins[c], HIGH);
  }
}
