#include <Arduino.h>
#include "Led.h"

Led::Led(int pin)
{
  pin_m = pin;
  pinMode(pin_m, OUTPUT);
}

void Led::on()
{
  digitalWrite(pin_m, HIGH);
}

void Led::off()
{
  digitalWrite(pin_m, LOW);
}
