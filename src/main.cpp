#include <Arduino.h>

#define BLUE_LED_PIN 16
#define YELLOW_LED_PIN 17
#define GREEN_LED_PIN 5

// put function declarations here:
int myFunction(int, int);

void setup() {
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(BLUE_LED_PIN, HIGH);
  delay(6000);
  digitalWrite(BLUE_LED_PIN, LOW);

  digitalWrite(YELLOW_LED_PIN, HIGH);
  delay(2000);
  digitalWrite(YELLOW_LED_PIN, LOW);

  digitalWrite(GREEN_LED_PIN, HIGH);
  delay(4000);
  digitalWrite(GREEN_LED_PIN, LOW);
}