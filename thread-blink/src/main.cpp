#include <stdio.h>
#include <stdlib.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>

#include "Led.H"

extern "C" {
    void app_main(void);
}

static void aux_blink(void* pvParam) {
    Led* led = static_cast<Led*>(pvParam);
    led->blink();
}

void app_main(void) {



    Led led1((gpio_num_t)14, 500);
    Led led2((gpio_num_t)15, 1000);

    led1.run();
    led2.run();
   
    xTaskCreate(&aux_blink, "LED1", 2048, &led1, 5, NULL);
    xTaskCreate(&aux_blink, "LED2", 2048, &led2, 5, NULL);

    vTaskDelay(portMAX_DELAY);
}

