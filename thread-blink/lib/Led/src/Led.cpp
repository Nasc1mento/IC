
#include <stdlib.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "Led.H"

Led::Led(gpio_num_t gpio_pin, uint16_t blink_interval) {
    this->gpio_pin = gpio_pin;
    this->blink_interval = blink_interval;
}

void Led::run() {
    esp_rom_gpio_pad_select_gpio(this->gpio_pin);
    gpio_set_direction(this->gpio_pin, GPIO_MODE_OUTPUT);
}

void Led::blink() {
    while(1)
    {
        gpio_set_level(this->gpio_pin, 1);
        vTaskDelay(this->blink_interval / portTICK_PERIOD_MS);
        gpio_set_level(this->gpio_pin, 0);
        vTaskDelay(this->blink_interval / portTICK_PERIOD_MS);
    }
}

void Led::destroy() {
    free(this);
}
