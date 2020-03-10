#ifndef __DHT11_H__
#define __DHT11_H__

#include "DHT.h"

class DHT11 : public DHT
{
  public:
    DHT11(byte pin);

    using DHT::read;
    bool read(float* humidity, float* temperature) override;
    unsigned long delayBeforeNextRead() override;

  private:
    unsigned long getStartDelay() override;
};

#endif
