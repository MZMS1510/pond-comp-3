#include <Arduino.h>
#include "Led.h"
#include "Semaforo.h"

#define RED_LED_PIN 16
#define YELLOW_LED_PIN 17
#define GREEN_LED_PIN 5

Led redLed(RED_LED_PIN);
Led yellowLed(YELLOW_LED_PIN);
Led greenLed(GREEN_LED_PIN);

Semaforo semaforo(&redLed, &yellowLed, &greenLed);

void setup() {}

void loop() {
  semaforo.run();
}