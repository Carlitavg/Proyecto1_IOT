#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(byte trigPin, byte echoPin) {
  this->trigPin = trigPin;
  this->echoPin = echoPin;
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float UltrasonicSensor::measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  unsigned long duration = pulseIn(echoPin, HIGH, 30000);
  distance = duration * 0.0343 / 2;
  return distance;
}

byte UltrasonicSensor::getLedForDistanceRange(byte port1, byte port2, byte port3) {
  float distance = measureDistance();
  if (distance < DistanceLowThreshold) {
    return port1;
  }
  else if (distance < DistanceHighThreshold) {
    return port2;
  }
  return port3;
}
float UltrasonicSensor::getDistance() {
    
    return distance;  
}
