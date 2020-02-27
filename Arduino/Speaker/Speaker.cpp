#include "Speaker.h"

int octave(int tone, int octaveNumber)
{
  return tone * pow(2, octaveNumber);
}

Speaker::Speaker(byte pin) : pin(pin) {}

void Speaker::begin()
{
  pinMode(pin, OUTPUT);
}

void Speaker::write(unsigned int frequency)
{
  tone(this->pin, frequency);
}

void Speaker::write(unsigned int frequency, unsigned long duration)
{
  tone(this->pin, frequency, duration);
}

void Speaker::shut()
{
  noTone(this->pin);
}
