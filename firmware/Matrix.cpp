#include "Matrix.h"

const uint8_t row_pins[MATRIX_ROW_COUNT] = {
  4, 3, 2, 16, 15, 7, 11
};

const uint8_t col_pins[MATRIX_COL_COUNT] = {
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
};

uint8_t debounce_time = 5;

Matrix::Matrix(void)
  : mcp(0, 27) {
  memset(keys, 0, sizeof(keys));

  mcp.begin();

  for (uint8_t c = 0; c < MATRIX_COL_COUNT; c++) {
      mcp.pinMode(col_pins[c], OUTPUT);
      mcp.digitalWrite(col_pins[c], HIGH);
  }

  for (uint8_t r = 0; r < MATRIX_ROW_COUNT; r++) {
      pinMode(row_pins[r], INPUT_PULLUP);
      digitalWrite(row_pins[r], HIGH);
  }

}

void Matrix::scan(Matrix::report *report) {
  memset(report, 0, sizeof(Matrix::report));

  auto scan_time = millis();

  for (uint8_t c = 0; c < MATRIX_COL_COUNT; c++) {            
  
    mcp.digitalWrite(col_pins[c], LOW);
  
    delayMicroseconds(30);
  
    for (uint8_t r = 0; r < MATRIX_ROW_COUNT; r++) {
      auto pressed = digitalRead(row_pins[r]) == LOW;

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
