#include "Ultrasonic.h"
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>


ultrasonic ultrasonic_init(uint8_t trigger_pin, uint8_t echo_pin) 
{
    ultrasonic u;
    u.trigger_pin = trigger_pin;
    u.echo_pin = echo_pin;
    return u;
}

void ultrasonic_setup(ultrasonic u) {
    esp_rom_gpio_pad_select_gpio(u.trigger_pin);
    esp_rom_gpio_pad_select_gpio(u.echo_pin);
    gpio_set_direction(u.trigger_pin, GPIO_MODE_OUTPUT);
    gpio_set_direction(u.echo_pin, GPIO_MODE_INPUT);
}



