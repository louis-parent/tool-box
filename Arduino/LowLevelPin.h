#ifndef __LOW_LEVEL_PIN_H__
#define __LOW_LEVEL_PIN_H__

#define setInputMode(mask, modeRegister) *modeRegister &= ~mask
#define setOutputMode(mask, modeRegister) *modeRegister |= mask

#define isHigh(mask, inRegister) (*inRegister & mask)
#define isLow(mask, inRegister) (!isHigh(mask, inRegister))
#define getState(mask, inRegister) isHigh(mask, inRegister)

#define setHigh(mask, outRegister) *outRegister |= mask
#define setLow(mask, outRegister) *outRegister &= ~mask

#define setPullup(mask, outRegister) setHigh(mask, outRegister)

#endif
