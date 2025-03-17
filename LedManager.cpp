#include "LedManager.h"

LedManager::LedManager(byte port1, byte port2, byte port3) 
    : leds{Led(port1), Led(port2), Led(port3)} { }

void LedManager::turnOnLed(byte pin) {
  static byte lastPin = 255;

  if (pin == lastPin) {
    return;
  }

  for (int i = 0; i < 3; i++) {
    if (leds[i].getPin() == pin) {
      leds[i].turnOn();
      lastPin = pin;  
    } else {
      leds[i].turnOff();
    }
  }
}