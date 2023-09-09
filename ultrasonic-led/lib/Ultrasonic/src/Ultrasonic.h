#ifndef Ultrasonic_h
#define Ultrasonic_h

#include <Arduino.h>


class Ultrasonic 
{
  public:
    Ultrasonic(uint8_t triggerPin, uint8_t echoPin);
    void run();
    uint16_t getDistance();
  private:
    uint8_t triggerPin;
    uint8_t echoPin;
};

#endif