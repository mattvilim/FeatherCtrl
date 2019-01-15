#ifndef HID_H
#define HID_H

#include <bluefruit.h>

class HID {
  public:
    HID(void);
    void begin(void);
    void sendKeys(void);
  private:
    BLEHidAdafruit bleHID;
    BLEDis bleDIS;
};


#endif
