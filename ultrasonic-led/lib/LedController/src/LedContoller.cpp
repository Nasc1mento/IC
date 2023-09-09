#include "LedController.h"
#include "Arduino.h"


LedController::LedController(uint8_t pin) 
{
  this->pin = pin;
}

void LedController::run() 
{
  pinMode(pin, OUTPUT);
}

void LedController::blinkBasedOnDistance(uint16_t distance) 
{
  uint16_t pause = getDelayByDistance(distance);
  digitalWrite(pin, HIGH);
  delay(pause);
  digitalWrite(pin, LOW);
  delay(pause);
}


uint16_t LedController::getDelayByDistance(uint16_t distance) 
{
  const uint8_t min_distance = 5;
  const uint8_t max_distance = 50;
  const uint8_t min_delay = 50;
  const uint16_t max_delay = 500;

  uint16_t distance_aux = constrain(distance, min_distance, max_distance);
  
  uint16_t distance_prop = (distance_aux - min_distance) / (max_distance - min_distance);
  uint16_t delay_time = min_delay + distance_prop * (max_delay - min_delay);

  return delay_time;
}