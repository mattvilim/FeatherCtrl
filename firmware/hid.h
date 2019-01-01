#ifndef HID_H
#define HID_H


struct hid {
  int temp;
};

void hid_init(struct hid *h);
void hid_send_keys(struct hid *h);

#endif
