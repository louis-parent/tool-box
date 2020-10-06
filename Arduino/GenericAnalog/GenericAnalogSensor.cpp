#include "GenericAnalogSensor.h"

GenericAnalogSensor::GenericAnalogSensor(byte analogPin) : analogPin(analogPin), analogMin(0), analogMax(1024), invert(false) {}
    
void GenericAnalogSensor::begin(bool invert)
{
  pinMode(this->analogPin, INPUT);
  this->setInverted(invert);
}

void GenericAnalogSensor::setInverted(bool invert)
{
  this->invert = invert;
}

void GenericAnalogSensor::calibrate(unsigned int min, unsigned int max)
{
  this->analogMin = min;
  this->analogMax = max;
}

byte GenericAnalogSensor::read() const
{
  return max(min(map(this->raw(), this->analogMin, this->analogMax, this->invert ? PERCENT_MAX : PERCENT_MIN, this->invert ? PERCENT_MIN : PERCENT_MAX), PERCENT_MAX), PERCENT_MIN);
}

unsigned int GenericAnalogSensor::raw() const
{
  return analogRead(this->analogPin);
}
