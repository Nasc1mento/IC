#include "LedController.h"
#include "Arduino.h"

LedController::LedController(int pin) {
  this->pin = pin;
}

void LedController::run() {
  pinMode(pin, OUTPUT);
}

void LedController::blink(int n) {
    int pause = getDelayByDistance(n);
    digitalWrite(pin, HIGH);
    delay(pause);
    digitalWrite(pin, LOW);
    delay(500);
}


int LedController::getDelayByDistance(int n) {
    int max_distance = 50;
    int min_distance = 5;
    int max_delay = 500;
    int min_delay = 50;
    int distance_aux = n;

    if (distance_aux > max_distance) {
        distance_aux = max_distance;
    }
    if (distance_aux < min_distance) {
        distance_aux = min_distance;
    }
    
    double distance_prop = (distance_aux - min_distance) / (max_distance - min_distance);
    int delay_time = min_delay + distance_prop * (max_delay - min_delay);

    return delay_time;
}