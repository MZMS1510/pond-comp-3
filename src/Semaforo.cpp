#include <Arduino.h>
#include "Semaforo.h"

Semaforo::Semaforo(Led *redLed, Led *yellowLed, Led *greenLed, Ultrasonic *ultrasonic) : redLed_m(*redLed),
                                                                                         yellowLed_m(*yellowLed),
                                                                                         greenLed_m(*greenLed),
                                                                                         ultrasonic_m(*ultrasonic),
                                                                                         state_m(RED) {}

void Semaforo::run()
{
  switch (this->state_m)
  {
  case RED:
    redLed_m.on();
    yellowLed_m.off();
    greenLed_m.off();
    delay(6000); // Red for 6 seconds
    this->state_m = GREEN;
    break;

  case YELLOW:
    redLed_m.off();
    yellowLed_m.on();
    greenLed_m.off();
    delay(2000);
    this->state_m = RED;
    break;

  case GREEN:
    redLed_m.off();
    yellowLed_m.off();
    greenLed_m.on();
    delay(4000); // Green for 4 seconds
    this->state_m = YELLOW;
    break;
  default:
    break;
  }
}