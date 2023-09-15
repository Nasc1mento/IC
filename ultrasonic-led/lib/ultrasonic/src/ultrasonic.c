#include "ultrasonic.h"
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_timer.h>


ultrasonic ultrasonic_init(uint8_t trigger_pin, uint8_t echo_pin) 
{
    ultrasonic u;
    u.trigger_pin = trigger_pin;
    u.echo_pin = echo_pin;
    return u;
}

void ultrasonic_setup(ultrasonic u) 
{
    esp_rom_gpio_pad_select_gpio(u.trigger_pin);
    esp_rom_gpio_pad_select_gpio(u.echo_pin);
    gpio_set_direction(u.trigger_pin, GPIO_MODE_OUTPUT);
    gpio_set_direction(u.echo_pin, GPIO_MODE_INPUT);
}

uint16_t ultrasonic_run(ultrasonic u) 
{
    gpio_set_level(u.trigger_pin, 1);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    gpio_set_level(u.trigger_pin, 0);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    while (gpio_get_level(u.echo_pin) == 0) {}
    int64_t start_time = esp_timer_get_time();
    while (gpio_get_level(u.echo_pin) == 1) {}
    int64_t end_time = esp_timer_get_time();

    uint16_t distance_calculated = (end_time - start_time) * 0.034 / 2;
    printf("Distance: %d cm\n", distance_calculated);
    return distance_calculated;
}

