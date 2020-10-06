#include "UART.h"

#include <util/delay_basic.h>
#include <limits.h>

#define setInputMode(mask, modeRegister) *modeRegister &= ~mask
#define setOutputMode(mask, modeRegister) *modeRegister |= mask

#define isHigh(mask, inRegister) (*inRegister & mask)
#define isLow(mask, inRegister) (!isHigh(mask, inRegister))
#define getState(mask, inRegister) isHigh(mask, inRegister)

#define setHigh(mask, outRegister) *outRegister |= mask
#define setLow(mask, outRegister) *outRegister &= ~mask

#define setPullup(mask, outRegister) setHigh(mask, outRegister)

#define waitCycles(cycles) _delay_loop_2(cycles)

#define writeBit(bit, mask, outRegister, bitLength) if(bit){ setHigh(mask, outRegister); }else{setLow(mask, outRegister);} waitCycles(bitLength)

#define getGoogLogic(bit, invertLogic) invertLogic ? !bit : bit

#define MSB 0b10000000

UART::UART(byte rxPin, byte txPin, bool invertLogic, unsigned long timeout)
{
  this->invertLogic = invertLogic;
  this->timeout = timeout;
  this->bitCycleLength = 0;
  
  this->rxMask = digitalPinToBitMask(rxPin);
  uint8_t rxPort = digitalPinToPort(rxPin);
  this->rxModeRegister = portModeRegister(rxPort);
  this->rxInRegister = portInputRegister(rxPort);

  this->txMask = digitalPinToBitMask(txPin);
  uint8_t txPort = digitalPinToPort(txPin);
  this->txModeRegister = portModeRegister(txPort);
  this->txOutRegister = portOutputRegister(txPort);
}

void UART::begin(unsigned int speed)
{
  unsigned int delay = (F_CPU / speed) / 4;
  this->bitCycleLength = this->positiveSubstraction(delay, 15 / 4);
  
  setInputMode(this->rxMask, this->rxModeRegister);
  setOutputMode(this->txMask, this->txModeRegister);

  if(this->invertLogic)
  {
    setLow(this->txMask, this->txOutRegister);
  }
  else
  {
    setHigh(this->txMask, this->txOutRegister);
  }
}

void UART::write(const byte* buffer, unsigned int length)
{
  for(unsigned int i = 0; i < length; i++)
  {
    this->write(buffer[i]);
  }
}
    
void UART::write(byte c)
{
  if(this->bitCycleLength > 0)
  {
    if(this->invertLogic)
    {
      c = ~c;  
    }
    
    noInterrupts();
    
    writeBit(getGoogLogic(UART::START_BIT, this->invertLogic), this->txMask, this->txOutRegister, this->bitCycleLength);

    byte mask = 1;
    
    for(byte i = 0; i < UART::MAX_BIT_PER_PACKET; i++)
    {
      writeBit(mask & c, this->txMask, this->txOutRegister, this->bitCycleLength);
      mask <<= 1;
    }
    
    writeBit(getGoogLogic(UART::STOP_BIT, this->invertLogic), this->txMask, this->txOutRegister, this->bitCycleLength);

    interrupts();
    delay(1);
  }
}

byte UART::read()
{
  byte received = 0;
  if(getState(this->rxMask, this->rxInRegister) == getGoogLogic(UART::START_BIT, this->invertLogic))
  {
    noInterrupts();

    waitCycles(this->bitCycleLength / 2);// Center to middle of the bits

    for(byte i = UART::MAX_BIT_PER_PACKET-1; i >= 0 ; i--)
    {
      waitCycles(this->bitCycleLength);
            
      received >>= 1;
      
      if(isHigh(this->rxMask, this->rxInRegister))
      {
        received |= MSB;
      }
    }
    
    if(this->invertLogic)
    {
      received = ~received;
    }

    waitCycles(this->bitCycleLength*3);
    
    interrupts();
  }

  return received;
}

unsigned int UART::positiveSubstraction(unsigned int left, unsigned int right)
{
  if(left > right)
  {
    return left - right;
  }
  else
  {
    return 1;
  }
}
