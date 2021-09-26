#ifndef __CHILD_PROCESS_H__
#define __CHILD_PROCESS_H__

#include <unistd.h>
#include <errno.h>

namespace std
{
	class ChildProcess
	{
		public:
			pid_t run()
			{
				pid_t pid = fork();
				
				if(pid == -1)
				{
					int errorCode = errno;
					throw system_error(error_code(errorCode, system_category()), "Failed create child process");
				}
				else if(pid == 0)
				{
					int exitCode = this->process();
					exit(exitCode);
				}	
				else
				{
					return pid;
				}
			}
		
		protected:
			virtual int process() = 0;
	};
}

#endif
