#include <Arduino.h>
#include "Semaforo.h"

enum State {
  RED,
  YELLOW,
  GREEN
};

class Semaforo {
private:
  Led redLed_m;
  Led yellowLed_m;
  Led greenLed_m;
  State state = RED;

public:
  Semaforo(Led* redLed, Led* yellowLed, Led* greenLed) :
    redLed_m(*redLed),
    yellowLed_m(*yellowLed),
    greenLed_m(*greenLed) {}

  void run() {
    switch (this->state)
    {
    case RED:
      redLed_m.on();
      yellowLed_m.off();
      greenLed_m.off();
      delay(6000); // Red for 6 seconds
      this->state = GREEN;
      break;
    
    case YELLOW:
      redLed_m.off();
      yellowLed_m.on();
      greenLed_m.off();
      delay(2000); // Yellow for 2 seconds
      this->state = RED;
      break;

    case GREEN:
      redLed_m.off();
      yellowLed_m.off();
      greenLed_m.on();
      delay(4000); // Green for 4 seconds
      this->state = YELLOW;
      break;
    default:
      break;
    }
  }
};