#include "HID.h"

HID::HID(void) {
}

void HID::begin(void) {
  Bluefruit.begin();
  Bluefruit.setName("FeatherCtrl");
  Bluefruit.setTxPower(-8);
  Bluefruit.autoConnLed(false);

  bleDIS.setManufacturer("TODO");
  bleDIS.setModel("TODO");
  
  bleDIS.begin();
  bleHID.begin();

  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);
  
  Bluefruit.Advertising.addService(bleHID);

  Bluefruit.Advertising.addName();
  
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);
  Bluefruit.Advertising.setFastTimeout(30);
  Bluefruit.Advertising.start(0);
}

void HID::sendKeys(void) {
}

