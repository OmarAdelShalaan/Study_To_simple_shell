#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t my_pid;
	pid_t my_parentPid;

    	my_pid = getpid();
    	my_parentPid = getppid();
	printf("my Pid: %d\n",my_pid);
	printf("my PPid: %d\n",my_parentPid);
	return 0;
}
