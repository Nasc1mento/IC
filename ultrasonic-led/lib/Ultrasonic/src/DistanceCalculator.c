#include "Ultrasonic.h"
#include <driver/gpio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <esp_timer.h>



uint16_t ultrasonic_calculate_distance(ultrasonic u) 
{
    gpio_set_level(u.trigger_pin, 1);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    gpio_set_level(u.trigger_pin, 0);
    vTaskDelay(1 / portTICK_PERIOD_MS);
    while (gpio_get_level(u.echo_pin) == 0) {}
    int64_t start_time = esp_timer_get_time();
    while (gpio_get_level(u.echo_pin) == 1) {}
    int64_t end_time = esp_timer_get_time();
    double distance = (end_time - start_time) * 0.0343 / 2;

    uint16_t distance_calculated = (end_time - start_time) * 0.034 / 2;
    return distance_calculated;
}