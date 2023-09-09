#include "Arduino.h"
#include "Ultrasonic.h"


Ultrasonic::Ultrasonic(uint8_t triggerPin, uint8_t echoPin) 
{
  this->triggerPin = triggerPin;
  this->echoPin = echoPin;
}

void Ultrasonic::run() 
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(triggerPin, LOW);
}

uint16_t Ultrasonic::getDistance()
{
  long duration;
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  uint16_t distance = (duration * 0.0343) / 2;
  return distance;
}
