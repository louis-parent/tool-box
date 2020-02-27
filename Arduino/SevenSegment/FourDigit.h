#ifndef __FOUR_DIGIT_H__
#define __FOUR_DIGIT_H__

#include <Arduino.h>
#include "SevenSegment.h"

#define DIGIT_NUMBER 4

class FourDigit
{
  public:
    FourDigit(byte pinSegA, byte pinSegB, byte pinSegC, byte pinSegD, byte pinSegE, byte pinSegF, byte pinSegG, byte pinSegDP, byte pinDigit1, byte pinDigit2, byte pinDigit3, byte pinDigit4);

    void begin();
    void write(String string);
    void clear();
    
  private:
    SevenSegment segments;
    byte digitsPins[DIGIT_NUMBER];
};

#endif
