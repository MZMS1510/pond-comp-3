#include <Arduino.h>
#include "Led.h"

#define RED_LED_PIN 16
#define YELLOW_LED_PIN 17
#define GREEN_LED_PIN 5

Led redLed(RED_LED_PIN);
Led yellowLed(YELLOW_LED_PIN);
Led greenLed(GREEN_LED_PIN);

void setup() {}

void loop() {
  redLed.on();
  delay(6000);
  redLed.off();

  yellowLed.on();
  delay(2000);
  yellowLed.off();

  greenLed.on();
  delay(4000);
  greenLed.off();
}