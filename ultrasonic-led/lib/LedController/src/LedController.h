#ifndef LedController_h
#define LedController_h

#include <Arduino.h>

class LedController {
  public:
    LedController(int pin);
    void run();
    void blink(int n);
  private:
    int pin;
    int getDelayByDistance(int n);
};

#endif