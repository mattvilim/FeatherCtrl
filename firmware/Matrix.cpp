#include "Matrix.h"

const uint8_t Matrix::rowPins[] = {
  [(int)Row::N1] = 4,
  [(int)Row::N2] = 3,
  [(int)Row::N3] = 2,
  [(int)Row::N4] = 16,
  [(int)Row::N5] = 15,
  [(int)Row::N6] = 7,
  [(int)Row::N7] = 11
};

const uint8_t Matrix::colPins[] = {
  [(int)Col::A] = 1,
  [(int)Col::B] = 2,
  [(int)Col::C] = 3,
  [(int)Col::D] = 4,
  [(int)Col::E] = 5,
  [(int)Col::F] = 6,
  [(int)Col::G] = 7,
  [(int)Col::H] = 8,
  [(int)Col::I] = 9,
  [(int)Col::J] = 10,
  [(int)Col::K] = 11,
  [(int)Col::L] = 12
};

void Matrix::begin(void) {
  mcp.begin();

  for (auto c = 0; c < (int)Matrix::Col::Count; c++) {
      mcp.pinMode(colPins[c], OUTPUT);
      mcp.digitalWrite(colPins[c], HIGH);
  }

  for (auto r = 0; r < (int)Matrix::Row::Count; r++) {
      pinMode(rowPins[r], INPUT_PULLUP);
      digitalWrite(rowPins[r], HIGH);
  }
}

Matrix::Matrix(void)
  : mcp(0, 27) {
  memset(keys, 0, sizeof(keys));
}

bool Matrix::scan(void) {
  auto scanTime = millis();

  bool update = false;

  for (auto c = 0; c < (int)Matrix::Col::Count; c++) {
  
    mcp.digitalWrite(colPins[c], LOW);
  
    delayMicroseconds(30);
  
    for (auto r = 0; r < (int)Matrix::Row::Count; r++) {
      auto pressed = digitalRead(rowPins[r]) == LOW;

      auto *keyOld = &keys[r][c];
      KeyState keyNew = { .pressTime = pressed, .pressed = scanTime };

      if (keyNew.pressed && !keyOld->pressed) {
        *keyOld = keyNew;
        Serial.println(r);
        Serial.println(c);
        update = true;
      } else if (!pressed && keyOld->pressed) {
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
