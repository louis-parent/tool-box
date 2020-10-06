#ifndef __LED_MATRIX_H__
#define __LED_MATRIX_H__

#include <Arduino.h>

#define MAX_MATRIX_SIZE 255

class LedMatrix
{
  public:
    LedMatrix(const byte* rowPins, const byte* columnPins, byte width, byte height);
    
    void begin();
    
    void display(const byte* pattern) const;
    void pixelAt(byte x, byte y);
    void clear() const;

  private:
    byte rowPins[MAX_MATRIX_SIZE];
    byte columnPins[MAX_MATRIX_SIZE];

    byte width;
    byte height;
};

#endif
