#ifndef BLINK_BASED_ON_DISTANCE_H
#define BLINK_BASED_ON_DISTANCE_H

#include "Ultrasonic.h"
#include "Led.h"

void blink_based_on_distance_setup(ultrasonic u, led l);
void blink_based_on_distance_run(ultrasonic u, led l);
uint16_t get_delay_by_distance(uint16_t distance);

#endif