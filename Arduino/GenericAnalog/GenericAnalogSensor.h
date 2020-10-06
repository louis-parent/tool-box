#ifndef __GENERIC_ANALOG_SENSOR_H__
#define __GENERIC_ANALOG_SENSOR_H__

#include <Arduino.h>

#define PERCENT_MAX 100
#define PERCENT_MIN 0

class GenericAnalogSensor
{
  public:
    GenericAnalogSensor(byte analogPin);
    
    void begin(bool invert = false);

    void setInverted(bool invert);
    void calibrate(unsigned int min, unsigned int max);
    
    byte read() const;
    unsigned int raw() const;

  private:
    byte analogPin;

    unsigned int analogMin;
    unsigned int analogMax;
    
    bool invert;
};

#endif
