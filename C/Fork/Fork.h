#ifndef __FORK_H__
#define __FORK_H__

#include <unistd.h>

pid_t runChildProcess(int (*process)(void*), void* params)
{
	pid_t pid = fork();
	
	if(pid != 0)
	{
		return pid;
	}
	else if(pid == 0)
	{
		int exitCode = (*process)(params);
		exit(exitCode);
	}
}

#endif
