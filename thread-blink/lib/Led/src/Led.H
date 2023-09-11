#ifndef LED_H
#define LED_H

#include <stdint.h>
#include <driver/gpio.h>

class Led {
    public:
        Led(gpio_num_t gpio_pin, uint16_t blink_interval);
        void run();
        void blink();
        void destroy();
    private:
        gpio_num_t gpio_pin;
        uint16_t blink_interval;
};



#endif
