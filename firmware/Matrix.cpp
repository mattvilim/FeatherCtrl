#include "Matrix.h"

const unsigned char row_pins[MATRIX_ROW_COUNT] = {
  4, 3, 2, 16, 15, 7, 11
};

const unsigned char col_pins[MATRIX_COL_COUNT] = {
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
};

const char debounce_time = 5;

Matrix::Matrix(void)
  : mcp(0, 27) {
  memset(keys, 0, sizeof(keys));

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

void Matrix::scan(Matrix::report *report) {
  memset(report, 0, sizeof(Matrix::report));

  unsigned char scan_time = millis();

  for (unsigned char c = 0; c < MATRIX_COL_COUNT; c++) {            
  
    mcp.digitalWrite(col_pins[c], LOW);
  
    delayMicroseconds(30);
  
    for (unsigned char r = 0; r < MATRIX_ROW_COUNT; r++) {
      unsigned char pressed = digitalRead(row_pins[r]) == LOW;

      auto *key_old = &keys[r][c];
      key key_new = { .pressed = pressed, .press_time = scan_time };

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
