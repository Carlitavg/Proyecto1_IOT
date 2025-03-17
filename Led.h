#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {

private:
  byte pin;
  bool isOn = false;

public:
  Led(byte pin);
  byte getPin();
  void turnOn();
  void turnOff();
};

#endif
