#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <Arduino.h>

#define NOT_PRESSED 0

class Button
{
  public:
    Button(byte pin);
    void begin();
    void refresh();
    unsigned long read();
    bool isPressed();
    void reset();

    static const short ONE_CLICK_DEFAULT_DELAY;
    
  private:
    byte pin;
    unsigned long pressedSince;
};

#endif
