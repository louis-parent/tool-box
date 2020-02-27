#include "Button.h"

const short Button::ONE_CLICK_DEFAULT_DELAY = 200;

Button::Button(byte pin) : pin(pin) {}

void Button::begin()
{
  pinMode(this->pin, INPUT_PULLUP);
}

void Button::refresh()
{
  if(digitalRead(this->pin) == LOW)
  {
    if(this->pressedSince == NOT_PRESSED)
    {
      this->pressedSince = millis();
    }
  }
  else
  {
    this->reset();
  }
}

unsigned long Button::read()
{
  this->refresh();
  return this->isPressed() ? (millis() - this->pressedSince) : 0;
}

bool Button::isPressed()
{
  this->refresh();
  return this->pressedSince != NOT_PRESSED;
}

void Button::reset()
{
  this->pressedSince = NOT_PRESSED;
}
