#include "Semaphore.h"

#include <sys/types.h>
#include <sys/sem.h>

Semaphore createSemaphore()
{
	return createSemaphoreWithKey(DEFAULT_KEY);
}

Semaphore createSemaphoreWithKey(const char* key)
{
	return semget(ftok(key, 0), 1, IPC_CREAT | 0666);
}

bool clearSemaphore(Semaphore sem)
{
	return semctl(sem, 0, IPC_RMID) != -1;
}

bool initSemaphore(Semaphore sem, int token)
{
	return semctl(sem, 0, SETVAL, token) != -1;
}

bool downSemaphoreOne(Semaphore sem)
{
	return downSemaphore(sem, 1);
}

bool downSemaphore(Semaphore sem, unsigned int token)
{
	return P(sem, token);
}

bool waitSemaphoreOne(Semaphore sem)
{
	return waitSemaphore(sem, 1);
}

bool waitSemaphore(Semaphore sem, unsigned int token)
{
	return P(sem, token);
}

bool acquireSemaphoreOne(Semaphore sem)
{
	return acquireSemaphore(sem, 1);
}

bool acquireSemaphore(Semaphore sem, unsigned int token)
{
	return P(sem, token);
}

bool procureSemaphoreOne(Semaphore sem)
{
	return procureSemaphore(sem, 1);
}

bool procureSemaphore(Semaphore sem, unsigned int token)
{
	return P(sem, token);
}

bool P(Semaphore sem, unsigned int token)
{
	return updateSemaphore(sem, token * -1);
}

bool upSemaphoreOne(Semaphore sem)
{
	return upSemaphore(sem, 1);
}

bool upSemaphore(Semaphore sem, unsigned int token)
{
	return V(sem, token);
}

bool signalSemaphoreOne(Semaphore sem)
{
	return signalSemaphore(sem, 1);
}

bool signalSemaphore(Semaphore sem, unsigned int token)
{
	return V(sem, token);
}

bool releaseSemaphoreOne(Semaphore sem)
{
	return  releaseSemaphore(sem, 1);
}

bool releaseSemaphore(Semaphore sem, unsigned int token)
{
	return V(sem, token);
}

bool vacateSemaphoreOne(Semaphore sem)
{
	return vacateSemaphore(sem, 1);
}

bool vacateSemaphore(Semaphore sem, unsigned int token)
{
	return V(sem, token);
}

bool V(Semaphore sem, unsigned int token)
{
	return updateSemaphore(sem, token);
}

void waitForZeroSemaphore(Semaphore sem)
{
	Z(sem);
}

void Z(Semaphore sem)
{
	updateSemaphore(sem, 0);
}

bool updateSemaphore(Semaphore sem, signed int token)
{
	struct sembuf op;
	op.sem_num = 0;
	op.sem_op = token;
	op.sem_flg = 0;
	
	return semop(sem, &op, 1) != -1;
}
