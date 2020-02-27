#ifndef __JOYSTICK_H__
#define __JOYSTICK_H__

#include "Potentiometer.h"
#include "Button.h"

class Joystick
{
  public:
    Joystick(byte xPin, byte yPin, byte button);
    void begin();
    void read(signed short& xValue, signed short& yValue, bool& isButtonPressed);
    signed short readX();
    signed short readY();
    bool isPressed();
    bool isHome();
    
  private:
    Potentiometer xAxis;
    Potentiometer yAxis;
    Button button;
};

#endif
