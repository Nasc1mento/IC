#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int triggerPin, int echoPin) {
  this->triggerPin = triggerPin;
  this->echoPin = echoPin;
}

void Ultrasonic::run() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(triggerPin, LOW);
}

double Ultrasonic::getDistance() {
  unsigned long time;
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  time = pulseIn(echoPin, HIGH);
  return time / 50;
}
