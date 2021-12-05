#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

pid_t fork();

int main()
{
	pid_t id;

	id = fork();
	
	if(id==-1)
		printf("\nError\n");
	else if(id==0)
	{
		printf("\nChild ID - %d\n",getpid());
		printf("Child PID - %d        -same\n",getppid());
	}
	else
	{
		printf("\nParent ID - %d\n",getpid());
		printf("Parent PID - %d        -same\n",getppid());
	}

}
