#include "Potentiometer.h"

Potentiometer::Potentiometer(byte pin) : pin(pin) {}

void Potentiometer::begin()
{
  pinMode(this->pin, INPUT);
}

unsigned short Potentiometer::read()
{
  Serial.println(analogRead(this->pin));
  return map(analogRead(this->pin), 0, 1024, 0, 100);
}
