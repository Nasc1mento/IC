#ifndef LED_H
#define LED_H

#include <stdint.h>

typedef struct
{
    uint8_t pin;
}led;

led led_init(uint8_t pin);
void led_setup(led led);
void led_on(led led);
void led_off(led led);
void led_run(led led, uint16_t delay_ms);

#endif