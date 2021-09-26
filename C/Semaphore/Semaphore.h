#ifndef __SEMAPHORE_H__
#define __SEMAPHORE_H__

#include <stdbool.h>

#define DEFAULT_KEY "__SEMAPHORE_H__"

typedef int Semaphore;

typedef struct {
	signed int val;
} SemaphoreInitializer;

Semaphore createSemaphore();

Semaphore createSemaphoreWithKey(const char* key);

bool clearSemaphore(Semaphore sem);

bool initSemaphore(Semaphore sem, int token);

bool downSemaphoreOne(Semaphore sem);
bool downSemaphore(Semaphore sem, unsigned int token);

bool waitSemaphoreOne(Semaphore sem);
bool waitSemaphore(Semaphore sem, unsigned int token);

bool acquireSemaphoreOne(Semaphore sem);
bool acquireSemaphore(Semaphore sem, unsigned int token);

bool procureSemaphoreOne(Semaphore sem);
bool procureSemaphore(Semaphore sem, unsigned int token);

bool P(Semaphore sem, unsigned int token);

bool upSemaphoreOne(Semaphore sem);
bool upSemaphore(Semaphore sem, unsigned int token);

bool signalSemaphoreOne(Semaphore sem);
bool signalSemaphore(Semaphore sem, unsigned int token);

bool releaseSemaphoreOne(Semaphore sem);
bool releaseSemaphore(Semaphore sem, unsigned int token);

bool vacateSemaphoreOne(Semaphore sem);
bool vacateSemaphore(Semaphore sem, unsigned int token);

bool V(Semaphore sem, unsigned int token);

void waitForZeroSemaphore(Semaphore sem);

void Z(Semaphore sem);

bool updateSemaphore(Semaphore sem, signed int token);

#endif
