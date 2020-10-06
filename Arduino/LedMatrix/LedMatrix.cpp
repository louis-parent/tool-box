#include "LedMatrix.h"

LedMatrix::LedMatrix(const byte* rowPins, const byte* columnPins, byte width, byte height) : width(width), height(height)
{ 
  for(int x = 0; x < this->width; x++)
  {
    this->columnPins[x] = columnPins[x];
  }

  for(int y = 0; y < this->height; y++)
  {
    this->rowPins[y] = rowPins[y];
  }
}
    
void LedMatrix::begin()
{
  byte pin;
  
  for(byte x = 0; x < this->width; x++)
  {
    pin = this->columnPins[x];
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }

  for(byte y = 0; y < this->height; y++)
  {
    pin = this->rowPins[y];
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
}

void LedMatrix::display(const byte* pattern) const
{
  for(byte y = 0; y < this->height; y++)
  {
    for(byte x = 0; x < this->width; x++)
    {
      if(pattern[y * this->width + x])
      {
        this->pixelAt(x, y);
      }
    }
  }
}

void LedMatrix::pixelAt(byte x, byte y)
{  
  digitalWrite(this->columnPins[x], LOW);
  digitalWrite(this->rowPins[y], HIGH);
  this->clear();
}

void LedMatrix::clear() const
{
  for(byte x = 0; x < this->width; x++)
  {
    digitalWrite(this->columnPins[x], HIGH);
  }

  for(byte y = 0; y < this->height; y++)
  {
    digitalWrite(this->rowPins[y], LOW);
  }
}
