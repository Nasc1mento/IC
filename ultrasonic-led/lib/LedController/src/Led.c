#include "Led.h"
#include "driver/gpio.h"

led led_init(uint8_t pin) 
{
    led l;
    l.pin = pin;
    return l;
}

void led_setup(led l) 
{
    esp_rom_gpio_pad_select_gpio(l.pin);
    gpio_set_direction(l.pin, GPIO_MODE_OUTPUT);
}

void led_on(led l) 
{
    gpio_set_level(l.pin, 1);
}

void led_off(led l) 
{
    gpio_set_level(l.pin, 0);
}