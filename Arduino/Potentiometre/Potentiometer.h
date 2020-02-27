#ifndef __POTENTIOMETER_H__
#define __POTENTIOMETER_H__

#include <Arduino.h>

class Potentiometer
{
  public:
    Potentiometer(byte pin);
    void begin();
    unsigned short read();
    
  private:
    byte pin;
};

#endif
