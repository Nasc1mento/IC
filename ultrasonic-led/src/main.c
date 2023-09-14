#include "Ultrasonic.h"
#include "Led.h"
#include "BlinkBasedOnDIstance.h"

void app_main() {
    ultrasonic u = ultrasonic_init(14, 35);
    led l = led_init(15);
    blink_based_on_distance_run(u, l);  
}