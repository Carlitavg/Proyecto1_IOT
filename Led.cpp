#include "Led.h"

Led::Led(byte pin) {
  this->pin = pin;
  pinMode(pin, OUTPUT);
  turnOff();
}

byte Led::getPin() {
  return pin;
}

void Led::turnOn() {
  digitalWrite(pin, HIGH);
  isOn = true;
}

void Led::turnOff() {
  digitalWrite(pin, LOW);
  isOn = false;
}