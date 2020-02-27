#ifndef __SPEAKER_H__
#define __SPEAKER_H__

#include <Arduino.h>

#define DO 65
#define D0# 69
#define REb 69
#define RE 74
#define RE# 78
#define MIb 78
#define MI 83
#define FA 87
#define FA# 93
#define SOLb 93
#define SOL 98
#define SOL# 104
#define LAb 104
#define LA 110
#define LA# 110
#define SIb 117
#define SI 123

int octave(int tone, int octaveNumber);

class Speaker
{
   public:
    Speaker(byte pin);

    void begin();
    void write(unsigned int frequency);
    void write(unsigned int frequency, unsigned long duration);
    void shut();
    
   private:
    byte pin;
};

#endif
