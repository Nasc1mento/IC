#include "ultrasonic.h"
#include "led.h"
#include "blink_based_on_distance.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


void app_main() 
{
    ultrasonic u = ultrasonic_init(14, 34);
    led l = led_init(2);
    blink_based_on_distance_run(u, l);
}