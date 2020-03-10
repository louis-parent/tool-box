#include "DHT22.h"

DHT22::DHT22(byte pin) : DHT(pin) {}

bool DHT22::read(float* humidity, float* temperature)
{
  byte data[DHT::DATA_LENGTH];
  byte returnCode = DHT::read(data);
  
  if(returnCode != DHT::NO_ERROR)
  {
    return false;
  }
  else
  {
    float humidityFromBytes = data[0];
    humidityFromBytes *= 256;
    humidityFromBytes += data[1];
    humidityFromBytes *= 0.1;
    *humidity = humidityFromBytes;
   
    float temperatureFromBytes = data[2] & 0x7f;
    temperatureFromBytes *= 256;
    temperatureFromBytes += data[3];
    temperatureFromBytes *= 0.1;
    
    bool isNegative = data[2] & 0x80;
    if(isNegative)
    {
      temperatureFromBytes *= -1;
    }
    
    *temperature = temperatureFromBytes;

    return true;
  }
}

unsigned long DHT22::delayBeforeNextRead()
{
  return 500;
}

unsigned long DHT22::getStartDelay()
{
  return 1;
}
