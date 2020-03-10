#ifndef __DHT22_H__
#define __DHT22_H__

#include "DHT.h"

class DHT22 : public DHT
{
  public:
    DHT22(byte pin);

    using DHT::read;
    bool read(float* humidity, float* temperature) override;
    unsigned long delayBeforeNextRead() override;

  private:
    unsigned long getStartDelay() override;
};

#endif
