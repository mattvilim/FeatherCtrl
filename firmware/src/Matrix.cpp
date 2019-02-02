#include "Matrix.h"

#include <Arduino.h>

const uint8_t Matrix::rowPins[] = {
  PIN_A2, PIN_A3, PIN_A4, PIN_A5, PIN_SPI_MOSI, PIN_WIRE_SCL, PIN_WIRE_SDA
};

const uint8_t Matrix::colPins[] = {
  5, 6, 10, 11, 12, 13, PIN_SERIAL_RX, PIN_SPI_MISO, PIN_SERIAL_TX, PIN_A1, PIN_A0, PIN_SPI_SCK
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
  }
}

bool Matrix::scan(void) {
  auto scanTime = millis();

  bool update = false;

  for (auto c = 0; c < (int)Matrix::Dim::Col; c++) {
  
    digitalWrite(colPins[c], LOW);
  
    for (auto r = 0; r < (int)Matrix::Dim::Row; r++) {
      auto pressed = digitalRead(rowPins[r]) == LOW;

      auto *keyOld = &keys[r][c];
      KeyState keyNew = { .pressTime = scanTime, .pressed = pressed };

      if (keyNew.pressed && !keyOld->pressed) {
        *keyOld = keyNew;
        update = true;
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

void Matrix::sleep(void) {
  for (auto c = 0; c < (int)Matrix::Dim::Col; c++) {
    digitalWrite(colPins[c], LOW);
  }

  for (auto r = 0; r < (int)Matrix::Dim::Row; r++) {
    nrf_gpio_cfg_sense_input(g_ADigitalPinMap[rowPins[r]], NRF_GPIO_PIN_PULLUP, NRF_GPIO_PIN_SENSE_LOW);
  }
}
