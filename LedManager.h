#ifndef LEDMANAGER_H
#define LEDMANAGER_H

#include "Led.h"

class LedManager {
private:
  Led* leds[3];
public:
  LedManager(byte port1, byte port2, byte port3);
  void turnOnLed(byte pin);
};

#endif