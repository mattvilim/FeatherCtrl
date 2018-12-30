#include <Arduino.h>
#include <bluefruit.h>

#include "config.h"
#include "keycodes.h"

BLEHidAdafruit blehid;
BLEDis bledis;

#define REPORT_KEYS 6

uint8_t report[REPORT_KEYS] = { 0 };
uint8_t active_mods = 0;

void
add_mods(
  uint8_t mods
) {
  active_mods |= mods;                      
}

void
del_mods(
  uint8_t mods
) {
  active_mods &= ~mods;          
}

void
send_report_keyboard() {
  bool err = blehid.keyboardReport(
    active_mods, report[0], report[1], report[2], report[3], report[4], report[5]
  );
}

void
register_keydown(uint16_t keycode) { 
    add_mods((uint8_t)(keycode >> 8));                        // keycode >> 8 = first byte of keycode (modifier)

    for (uint8_t i = 0; i < REPORT_KEYS; i++) {
      // Key already stored there
      if (report[i] == (uint8_t)(keycode & 0xFF)) {           // keycode & 0xFF = last byte of the keycode (key value)
        break;
      }
      // Empty key space
      if (report[i] == 0) {
        // Store key
        report[i] = (uint8_t)(keycode & 0xFF);
        break;
      }
    }
    
    send_report_keyboard();
}

void
register_keyup(uint16_t keycode) {
    del_mods((uint8_t)(keycode >> 8));

    for (uint8_t i = 0; i < REPORT_KEYS; i++) {
      if (report[i] == (uint8_t)(keycode & 0xFF)) {           // Look for where the key is stored
        report[i] = 0;                                        // Clear it from report array
      }
    }

    send_report_keyboard();
}

void
init_bluetooth() {

  Bluefruit.begin();
  Bluefruit.setName("FeatherCtrl");
  Bluefruit.setTxPower(-8);
  Bluefruit.autoConnLed(false);

  //bledis.setManufacturer("mike wu");
  //bledis.setModel("Kinesis Advantage 2");
  
  bledis.begin();
  blehid.begin();

  Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
  Bluefruit.Advertising.addTxPower();
  Bluefruit.Advertising.addAppearance(BLE_APPEARANCE_HID_KEYBOARD);
  
  Bluefruit.Advertising.addService(blehid);

  Bluefruit.Advertising.addName();
  
  Bluefruit.Advertising.restartOnDisconnect(true);
  Bluefruit.Advertising.setInterval(32, 244);
  Bluefruit.Advertising.setFastTimeout(30);
  Bluefruit.Advertising.start(0);
}

bool
bluetooth_connected() {
  return Bluefruit.connected();
}
