#include "Matrix.h"

const uint8_t Matrix::rowPins[] = {
  4, 3, 2, 16, 15, 7, 11
};

const uint8_t Matrix::colPins[] = {
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
};

Matrix::Matrix(void)
  : mcp(0, 27) {
  memset(keys, 0, sizeof(keys));
}

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

bool Matrix::scan(void) {
  auto scanTime = millis();

  bool update = false;

  for (auto c = 0; c < (int)Matrix::Dim::Col; c++) {
  
    mcp.digitalWrite(colPins[c], LOW);
  
    delayMicroseconds(30);
  
    for (auto r = 0; r < (int)Matrix::Dim::Row; r++) {
      auto pressed = digitalRead(rowPins[r]) == LOW;

      auto *keyOld = &keys[r][c];
      KeyState keyNew = { .pressTime = scanTime, .pressed = pressed };

      if (keyNew.pressed && !keyOld->pressed) {
        *keyOld = keyNew;
        update = true;
        Serial.print(r);
        Serial.print(c);
      } else if (!keyNew.pressed && keyOld->pressed) {
        if (keyNew.pressTime - keyOld->pressTime > debounceTime) {
          keyOld->pressed = false;
          update = true;
        }
      }
    }
  
    mcp.digitalWrite(colPins[c], HIGH);
  }

  return update;
}

bool Matrix::pressed(const Matrix::Key k) const {
  return keys[k.r][k.c].pressed;
}
