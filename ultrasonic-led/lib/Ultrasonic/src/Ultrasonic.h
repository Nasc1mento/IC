#ifndef Ultrasonic_h
#define Ultrasonic_h

#include <Arduino.h>


class Ultrasonic {
  public:
    Ultrasonic(int triggerPin, int echoPin);
    void run();
    double getDistance();
  private:
    int triggerPin;
    int echoPin;
};

#endif