#include "DHT.h"

DHT::DHT(byte pin) : pin(pin) {}

void DHT::begin(unsigned long timeout)
{
  this->timeout = timeout;
  pinMode(this->pin, INPUT_PULLUP);
}

bool DHT::read(float* humidity, float* temperature, float* dewPoint)
{ 
  this->read(humidity, temperature);
  *dewPoint = DHT::dewPoint(*humidity, *temperature);
}
        
float DHT::readHumidity()
{
  float humidity, temperature;
  this->read(&humidity, &temperature);
  return humidity;
}
float DHT::readTemperature()
{
  float humidity, temperature;
  this->read(&humidity, &temperature);
  return temperature;
}

float DHT::dewPoint(float humidity, float temperature)
{
  // Approximation constants, see http://en.wikipedia.org/wiki/Dew_point
  const double a = 17.27;
  const double b = 237.7;

  double dewTemperature = (a * temperature) / (b + temperature) + log(humidity * 0.01);
  return (b * dewTemperature) / (a - dewTemperature);
}

byte DHT::read(byte data[DHT::DATA_LENGTH])
{
  data[0] = data[1] = data[2] = data[3] = data[4] = 0;
 
  uint8_t mask = digitalPinToBitMask(pin);
  uint8_t port = digitalPinToPort(pin);
  
  volatile uint8_t* modeRegister = portModeRegister(port);
  volatile uint8_t* outRegister = portOutputRegister(port);
  volatile uint8_t* inRegister = portInputRegister(port);

  unsigned long wakeUpDelay = this->getStartDelay();
  
  unsigned long timeoutCycles = microsecondsToClockCycles(this->timeout);

  unsigned long currentTimeout = 0;

  /* Set pull-up mode */
  *outRegister |= mask;  // PULLUP
  *modeRegister &= ~mask; // INPUT
  delay(100);
 
  /* Wake up sensor */
  *modeRegister |= mask;  // OUTPUT
  *outRegister &= ~mask; // LOW
  delay(wakeUpDelay);
  
  noInterrupts();
  
  /* Set reading */
  *outRegister |= mask;  // PULLUP
  delayMicroseconds(40);
  *modeRegister &= ~mask; // INPUT
 
  /* Wait for sensor answer */
  currentTimeout = 0;
  while(!(*inRegister & mask)) // Wait LOW value
  {
    if (++currentTimeout >= timeoutCycles)
    {
        interrupts();
        return DHT::TIMEOUT_ERROR;
      }
  }
    
  currentTimeout = 0;
  while(*inRegister & mask) // Wait HIGH value
  {
    if (++currentTimeout >= timeoutCycles)
    {
        interrupts();
        return DHT::TIMEOUT_ERROR;
      }
  }

  /* Read values (40 bits) */
  for (byte i = 0; i < 40; ++i)
  {
 
    /* Wait LOW */
    unsigned long cycles_low = 0;
    while(!(*inRegister & mask))
    {
      if (++cycles_low >= timeoutCycles)
      {
        interrupts();
        return DHT::TIMEOUT_ERROR;
      }
    }

    /* Wait HIGH */
    unsigned long cycles_high = 0;
    while(*inRegister & mask)
    {
      if (++cycles_high >= timeoutCycles)
      {
        interrupts();
        return DHT::TIMEOUT_ERROR;
      }
    }
    
    data[i / 8] <<= 1;
    if (cycles_high > cycles_low) /* bit is 1 if true, 0 else */
    {
      data[i / 8] |= 1;
    }
  }
  
  interrupts();
   
  return this->checkSum(data) ? DHT::NO_ERROR : DHT::CHECKSUM_ERROR;
}

bool DHT::checkSum(byte data[DHT::DATA_LENGTH])
{
  byte checksum = (data[0] + data[1] + data[2] + data[3]) & 0xff;
  return data[4] == checksum;
}
