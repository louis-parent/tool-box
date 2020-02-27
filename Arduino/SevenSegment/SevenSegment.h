#ifndef __SEVEN_SEGMENT_H__
#define __SEVEN_SEGMENT_H__

#include <Arduino.h>

class SevenSegment
{
  public:
    SevenSegment(byte pinSegA, byte pinSegB, byte pinSegC, byte pinSegD, byte pinSegE, byte pinSegF, byte pinSegG, byte pinSegDP);

    void begin();
    void write(char c);
    void clear();

  private:
    byte pinSegA;
    byte pinSegB; 
    byte pinSegC;
    byte pinSegD;
    byte pinSegE;
    byte pinSegF;
    byte pinSegG;
    byte pinSegDP;
};

#endif
