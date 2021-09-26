#include "Semaphore.h"

#include <sys/types.h>
#include <sys/sem.h>

namespace std
{
	Semaphore::Semaphore(const std::string& key, int tokens)
	{
		this->id = semget(ftok(key.c_str(), 0), 1, IPC_CREAT | 0666);
		this->init(tokens);
	}

	bool Semaphore::init(int tokens)
	{
		return semctl(this->id, 0, SETVAL, tokens) != -1;
	}

	bool Semaphore::clear()
	{
		return semctl(this->id, 0, IPC_RMID) != -1;
	}

	bool Semaphore::update(signed int token)
	{
		struct sembuf op;
		op.sem_num = 0;
		op.sem_op = token;
		op.sem_flg = 0;
		
		return semop(this->id, &op, 1) != -1;
	}
}
