#include "SevenSegment.h"

SevenSegment::SevenSegment(byte pinSegA, byte pinSegB, byte pinSegC, byte pinSegD, byte pinSegE, byte pinSegF, byte pinSegG, byte pinSegDP) : pinSegA(pinSegA), pinSegB(pinSegB), pinSegC(pinSegC), pinSegD(pinSegD), pinSegE(pinSegE), pinSegF(pinSegF), pinSegG(pinSegG), pinSegDP(pinSegDP) {}

void SevenSegment::begin()
{
  pinMode(this->pinSegA, OUTPUT);
  pinMode(this->pinSegB, OUTPUT);
  pinMode(this->pinSegC, OUTPUT);
  pinMode(this->pinSegD, OUTPUT);
  pinMode(this->pinSegE, OUTPUT);
  pinMode(this->pinSegF, OUTPUT);
  pinMode(this->pinSegG, OUTPUT);
  pinMode(this->pinSegDP, OUTPUT);

  this->clear();
}

void SevenSegment::write(char c)
{    
  this->clear();
  
  switch(c)
  {
    case '0':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      break;

    case '1':
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      break;

    case '2':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegB, HIGH); 
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      break;

    case '3':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      break;
      
    case '4':
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      break;

    case '5':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      break;

    case '6':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      break;

    case '7':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      break;

    case '8':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      break;

    case '9':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      break;

    case 'a':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      break;

    case 'b':
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      break;

    case 'c':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      break;

    case 'd':
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      break;

    case 'e':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      break;

    case 'f':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      break;

    case 'g':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      break;

    case 'h':
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      break;

    case 'i':
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      break;

    case 'j':
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      break;

    case 'l':
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      break;

    case 'n':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      break;

    case 'o':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      break;

    case 'p':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      break;

    case 'q':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      break;

    case 'r':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      break;

    case 's':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      break;

    case 't':
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      break;

    case 'u':
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      digitalWrite(this->pinSegE, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      break;

    case 'y':
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegC, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      break;

    case '-':
      digitalWrite(this->pinSegG, HIGH);
      break;

    case '_':
      digitalWrite(this->pinSegD, HIGH);
      break;

    case '.':
      digitalWrite(this->pinSegDP, HIGH);
      break;

    case ',':
      digitalWrite(this->pinSegDP, HIGH);
      break;

    case ' ':
      break;

    case '=':
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegD, HIGH);
      break;

   case '°':
      digitalWrite(this->pinSegA, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      digitalWrite(this->pinSegG, HIGH);
      digitalWrite(this->pinSegF, HIGH);
      break;

   case '\'':
      digitalWrite(this->pinSegF, HIGH);
      break;

   case '"':
      digitalWrite(this->pinSegF, HIGH);
      digitalWrite(this->pinSegB, HIGH);
      break;
  }
}

void SevenSegment::clear()
{
  digitalWrite(this->pinSegA, LOW);
  digitalWrite(this->pinSegB, LOW);
  digitalWrite(this->pinSegC, LOW);
  digitalWrite(this->pinSegD, LOW);
  digitalWrite(this->pinSegE, LOW);
  digitalWrite(this->pinSegF, LOW);
  digitalWrite(this->pinSegG, LOW);
  digitalWrite(this->pinSegDP, LOW);
}
