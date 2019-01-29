#include "Matrix.h"

#include <Arduino.h>

const uint8_t Matrix::rowPins[] = {
  PIN_A2, PIN_A3, PIN_A4, PIN_A5, PIN_SPI_MOSI, PIN_WIRE_SCL, PIN_WIRE_SDA
};

const uint8_t Matrix::colPins[] = {
  27, PIN_A6, 11, 7, 15, 16, PIN_SERIAL_RX, PIN_SPI_MISO, PIN_SERIAL_TX, PIN_A1, PIN_A0, PIN_SPI_SCK
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
        //Serial.print(r);
        //Serial.print(c);
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
