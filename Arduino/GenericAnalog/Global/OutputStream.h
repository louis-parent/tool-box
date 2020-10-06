#ifndef __OUTPUT_STREAM_H__
#define __OUTPUT_STREAM_H__

class OutputStream
{
  public:
    virtual void write(byte b) = 0;
    
    virtual void write(byte* buffer, unsigned int length)
    {
      for(int i = 0; i < length; i++)
      {
        this->write(buffer[i]);  
      }
    }
};

#endif
