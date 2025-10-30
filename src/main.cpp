#include <Arduino.h>
#include "Led.h"
#include "Semaforo.h"
#include "Ultrasonic.h"

#define RED_LED_PIN 16
#define YELLOW_LED_PIN 17
#define GREEN_LED_PIN 5
#define TRIGGER_PIN 32
#define ECHO_PIN 35

Led redLed(RED_LED_PIN);
Led yellowLed(YELLOW_LED_PIN);
Led greenLed(GREEN_LED_PIN);

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

Semaforo semaforo(&redLed, &yellowLed, &greenLed, &ultrasonic);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  semaforo.run();

  float distance = ultrasonic.readDistanceCM();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}