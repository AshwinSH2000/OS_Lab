#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t pid;
	pid=fork();
	if(pid==0)
	{
		printf("\n\tThis is the child process");
		printf("\n\tThe pid of parent process:%d\n", getppid());
	}
	else if(pid>0)
	{
		printf("\n\tThis is the parent process");
		printf("\n\tThe pid of the child process:%d\n", pid);
	}
	else
		printf("\n\tThere was error in creating the child process");
	return 0;
}

