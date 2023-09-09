#ifndef LedController_h
#define LedController_h

#include <Arduino.h>


class LedController 
{
  public:
    LedController(uint8_t pin);
    void run();
    void blinkBasedOnDistance(uint16_t distance);
  private:
    uint8_t pin;
    uint16_t getDelayByDistance(uint16_t distance);
};

#endif