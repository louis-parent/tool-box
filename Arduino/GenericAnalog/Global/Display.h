#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include "OutputStream.h"

class Display : OuputStream
{
  public:
    void print(String str)
    {
      this->write(str.c_str(), str.length());
    }

    void println(String str)
    {
      this->print(str);
      this->print("\n");
    }
};

#endif
