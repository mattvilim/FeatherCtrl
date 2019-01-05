#include "Matrix.h"

const uint8_t rowPins[(int)Matrix::Dim::Row] = {
  4, 3, 2, 16, 15, 7, 11
};

const uint8_t colPins[(int)Matrix::Dim::Col] = {
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
};

uint8_t debounce_time = 5;

void Matrix::begin(void) {
  mcp.begin();

  for (auto c = 0; c < (int)Matrix::Dim::Col; c++) {
      mcp.pinMode(colPins[c], OUTPUT);
      mcp.digitalWrite(colPins[c], HIGH);
  }

  for (auto r = 0; r < (int)Matrix::Dim::Row; r++) {
      pinMode(rowPins[r], INPUT_PULLUP);
      digitalWrite(rowPins[r], HIGH);
  }
}

Matrix::Matrix(void)
  : mcp(0, 27) {
  memset(keys, 0, sizeof(keys));

}

void Matrix::scan(Matrix::Report *report) {
  memset(report, 0, sizeof(Matrix::Report));

  auto scanTime = millis();

  for (auto c = 0; c < (int)Matrix::Dim::Col; c++) {
  
    mcp.digitalWrite(colPins[c], LOW);
  
    delayMicroseconds(30);
  
    for (auto r = 0; r < (int)Matrix::Dim::Row; r++) {
      auto pressed = digitalRead(rowPins[r]) == LOW;

      auto *keyOld = &keys[r][c];
      KeyState keyNew = { .pressed = pressed, .pressTime = scanTime };

      if (keyNew.pressed && !keyOld->pressed) {
        *keyOld = keyNew;
        report->pressed[r] |= 1 << c;
        Serial.println(r);
        Serial.println(c);
      } else if (!pressed && keyOld->pressed) {
        if (keyNew.pressTime - keyOld->pressTime > debounce_time) {
          keyOld->pressed = false;
          report->released[r] |= 1 << c;
        }
      }
    }
  
    mcp.digitalWrite(colPins[c], HIGH);
  }
}
