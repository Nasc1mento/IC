#include "Led.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


void led_blink(led l, uint16_t delay_ms) 
{
    led_setup(l);
    led_on(l);
    vTaskDelay(delay_ms / portTICK_PERIOD_MS);
    led_off(l);
    vTaskDelay(delay_ms / portTICK_PERIOD_MS);
}