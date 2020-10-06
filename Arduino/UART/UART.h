#ifndef __UART_H__
#define __UART_H__

#include <Arduino.h>

class UART
{
  public:
    UART(byte rxPin, byte txPin, bool invertLogic = false, unsigned long timeout = 1000);
    void begin(unsigned int speed);

    void write(const byte* buffer, unsigned int length);
    void write(byte c);
    
    byte read();

    static const unsigned int SECOND_IN_MICRO = 1000000;
    static const unsigned int STANDARD_SPEED[24] = {50, 75, 110, 134.5, 150, 300, 600, 1200, 1800, 2400, 4800, 7200, 9600, 14400, 19200, 38400, 56000, 57600, 76800, 115200, 128000, 230400, 256000, 460800};

    static const bool START_BIT = LOW;
    static const bool STOP_BIT = HIGH;

    static const byte MAX_BIT_PER_PACKET = 8;
    
  private:
    bool invertLogic;

    unsigned long timeout;
    
    uint8_t rxMask;
    uint8_t* rxModeRegister;
    uint8_t* rxInRegister;
    
    uint8_t txMask;
    uint8_t* txModeRegister;
    uint8_t* txOutRegister;
    
    unsigned int bitCycleLength;
    
    unsigned int positiveSubstraction(unsigned int left, unsigned int right);
};

#endif
