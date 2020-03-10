#ifndef __DHT_H__
#define __DHT_H__

#include <Arduino.h>

class DHT
{
  public:
    DHT(byte pin);
    void begin(unsigned long timeout = 1000);
    
    virtual bool read(float* humidity, float* temperature) = 0;
    virtual bool read(float* humidity, float* temperature, float* dewPoint);
    
    virtual float readHumidity();
    virtual float readTemperature();

    virtual unsigned long delayBeforeNextRead() = 0;

    static float dewPoint(float humidity, float temperature);

  protected:
    static const int DATA_LENGTH = 5;
    static const int DATA_BITS = sizeof(byte[DHT::DATA_LENGTH]);

    static const byte NO_ERROR = 0;
    static const byte TIMEOUT_ERROR = 1;
    static const byte CHECKSUM_ERROR = 2;

    virtual unsigned long getStartDelay() = 0;
    
    byte read(byte data[DHT::DATA_LENGTH]);
    bool checkSum(byte data[DHT::DATA_LENGTH]);
  
  private:  
    byte pin;
    unsigned long timeout;
};

#endif
