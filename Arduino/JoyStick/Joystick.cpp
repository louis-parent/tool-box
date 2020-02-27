#include "Joystick.h"

Joystick::Joystick(byte xPin, byte yPin, byte buttonPin) : xAxis(xPin), yAxis(yPin), button(buttonPin) {}

void Joystick::begin()
{
  this->xAxis.begin();
  this->yAxis.begin();

  this->button.begin();
}

void Joystick::read(signed short& xValue, signed short& yValue, bool& isButtonPressed)
{
  xValue = this->readX();  
  yValue = this->readY();

  isButtonPressed = this->isPressed();
}

signed short Joystick::readX()
{
  return map(this->xAxis.read(), 0, 100, -100, 100);
}

signed short Joystick::readY()
{
  return map(this->yAxis.read(), 0, 100, -100, 100);
}

bool Joystick::isPressed()
{
  return this->button.isPressed();  
}

bool Joystick::isHome()
{
  return this->readX() == 0 && this->readY() == 0;
}
