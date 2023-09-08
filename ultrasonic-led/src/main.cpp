#include <Arduino.h>
#include <stdio.h>
#include <Ultrasonic.h>
#include <LedController.h>

Ultrasonic ultrasonic(13, 34);
LedController ledController(14);

void setup()
{
  Serial.begin(115200);
  ultrasonic.run();
  ledController.run();
}

void loop()
{
  double distance = ultrasonic.getDistance();
  ledController.blink(distance);
  Serial.println(distance);
  delay(500);
}
