#include "Matrix.h"

#include <Arduino.h>

const uint8_t Matrix::rowPins[] = {
  4, 5, 28, 29, 13, 26, 25
};

const uint8_t Matrix::colPins[] = {
  27, 30, 11, 7, 15, 16, 6, 14, 8, 3, 2, 12
};

Matrix::Matrix(void) {
  memset(keys, 0, sizeof(keys));
}

void Matrix::begin(void) {
  for (auto c = 0; c < (int)Matrix::Dim::Col; c++) {
      pinMode(colPins[c], OUTPUT);
      digitalWrite(colPins[c], HIGH);
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
  
    digitalWrite(colPins[c], LOW);
  
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
  
    digitalWrite(colPins[c], HIGH);
  }

  return update;
}

bool Matrix::pressed(const Matrix::Key k) const {
  return keys[k.r][k.c].pressed;
}
