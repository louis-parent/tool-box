#include "DHT11.h"

DHT11::DHT11(byte pin) : DHT(pin) {}

bool DHT11::read(float* humidity, float* temperature)
{
  byte data[DHT::DATA_LENGTH];
  byte returnCode = DHT::read(data);
  
  if(returnCode != DHT::NO_ERROR)
  {
    return false;
  }
  else
  {
    *humidity = data[0];
    *temperature = data[2];

    return true;
  }
}

unsigned long DHT11::delayBeforeNextRead()
{
  return 1000;
}

unsigned long DHT11::getStartDelay()
{
  return 18;
}
