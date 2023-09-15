#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <stdint.h>

typedef struct 
{
    uint8_t trigger_pin;
    uint8_t echo_pin;
}ultrasonic;

ultrasonic ultrasonic_init(uint8_t trigger_pin, uint8_t echo_pin);
void ultrasonic_setup(ultrasonic u);
uint16_t ultrasonic_run(ultrasonic u);

#endif