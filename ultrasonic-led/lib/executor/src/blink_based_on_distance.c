#include "blink_based_on_distance.h"
#include <stdio.h> 
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


uint16_t distance;

static void led_task(void *arg)
{
    led l = *(led *)arg;
    while (1)
    {
        uint16_t delay_ms = get_delay_by_distance(distance);
        led_run(l, delay_ms);
    }
}

static void ultrasonic_task(void *arg)
{
    ultrasonic u = *(ultrasonic *)arg;
    while (1)
    {
        distance = ultrasonic_run(u);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

void blink_based_on_distance_setup(ultrasonic u, led l)
{
    ultrasonic_setup(u);
    led_setup(l);
}

void blink_based_on_distance_run(ultrasonic u, led l)
{
    blink_based_on_distance_setup(u, l);

    xTaskCreate(&ultrasonic_task, "ultrasonic_task", 2048, &u, 5, NULL);
    xTaskCreate(&led_task, "led_task", 2048, &l, 6, NULL);
    vTaskDelay(portMAX_DELAY);
}

uint16_t get_delay_by_distance(uint16_t distance)
{
    const uint16_t min_distance = 5;
    const uint16_t max_distance = 50;
    const uint16_t min_delay = 50;
    const uint16_t max_delay = 500;
    uint16_t distance_aux = distance;

    if (distance_aux > max_distance)
    {
        distance_aux = max_distance;
    }
    else if (distance_aux < min_distance)
    {
        distance_aux = min_distance;
    }

    uint16_t distance_range = max_distance - min_distance;
    uint16_t distance_prop = (distance_aux - min_distance) * 100 / distance_range;
    uint16_t delay_time = (distance_prop * (max_delay - min_delay) / 100) + min_delay;

    return delay_time;
}

