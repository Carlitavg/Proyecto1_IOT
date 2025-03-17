#include "LedManager.h"
#include "UltrasonicSensor.h"
static const byte pinTrigSensor = 32;
static const byte pinEchoSensor = 33;
static const byte pinLed1 = 5;
static const byte pinLed2 = 15;
static const byte pinLed3 = 4;

UltrasonicSensor sensor(pinTrigSensor, pinEchoSensor);
LedManager leds(pinLed1, pinLed2, pinLed3);

void setup() {
  Serial.begin(115200);
}

void loop() {
  float cm = sensor.getDistance();
  float inches = cm / 2.54;
  
  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.println(" cm");
  
  delay(100);

  leds.turnOnLed(sensor.getLedForDistanceRange(pinLed1, pinLed2, pinLed3));
}
