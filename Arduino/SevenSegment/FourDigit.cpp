#include "FourDigit.h"

FourDigit::FourDigit(byte pinSegA, byte pinSegB, byte pinSegC, byte pinSegD, byte pinSegE, byte pinSegF, byte pinSegG, byte pinSegDP, byte pinDigit1, byte pinDigit2, byte pinDigit3, byte pinDigit4) : segments(pinSegA, pinSegB, pinSegC, pinSegD, pinSegE, pinSegF, pinSegG, pinSegDP)
{
  this->digitsPins[0] = pinDigit1;
  this->digitsPins[1] = pinDigit2;
  this->digitsPins[2] = pinDigit3;
  this->digitsPins[3] = pinDigit4;     
}

void FourDigit::begin()
{
  this->segments.begin();

  for(byte i = 0; i < DIGIT_NUMBER; i++)
  {
    pinMode(this->digitsPins[i], OUTPUT);
  }

  this->clear();
}

void FourDigit::write(String string)
{
  string.toLowerCase();
    
  for(byte i = 0; i < min(string.length(), DIGIT_NUMBER); i++)
  {    
    this->clear();
    digitalWrite(this->digitsPins[i], LOW);
    this->segments.write(string.charAt(i));
  }
}

void FourDigit::clear()
{
  this->segments.clear();

  for(byte i = 0; i < DIGIT_NUMBER; i++)
  {
    digitalWrite(this->digitsPins[i], HIGH);
  }
}
