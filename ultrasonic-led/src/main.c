#include "Ultrasonic.h"
#include "Led.h"
#include "BlinkBasedOnDIstance.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


void app_main() {
    // ultrasonic u = ultrasonic_init(14, 34);
    // ultrasonic_setup(u);
    // for (;;) {
    //     ultrasonic_run(u);
    //     vTaskDelay(1000 / portTICK_PERIOD_MS);
    // }

    ultrasonic u = ultrasonic_init(14, 34);
    led l = led_init(2);
    blink_based_on_distance_setup(u, l);
    blink_based_on_distance_run(u, l);
    
}