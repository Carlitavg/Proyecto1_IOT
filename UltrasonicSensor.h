#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

#include <Arduino.h>

class UltrasonicSensor {
private:
  byte trigPin;
  byte echoPin;
  float distance = 0.0;

public:

  static const byte DistanceLowThreshold = 30;
  static const byte DistanceHighThreshold = 60;

  UltrasonicSensor(byte trigPin, byte echoPin);
  float measureDistance();
  byte getLedForDistanceRange(byte port1, byte port2, byte port3);
  float getDistance();
};

#endif