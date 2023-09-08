#include <Arduino.h>
#include <stdio.h>
#include <Ultrasonic.h>

Ultrasonic ultrasonic(13, 34);

void setup()
{
  Serial.begin(115200);
  ultrasonic.run();
}

void loop()
{
  double distance = ultrasonic.getDistance();
  Serial.println(distance);
  delay(500);
}
