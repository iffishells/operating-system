/* fork: create a new process */
#include <stdlib.h> /* needed to define exit() */
#include <unistd.h> /* needed for fork() */
#include <sys/wait.h> /* needed for wait() */
#include <stdio.h> /* needed for printf() */
int main(int argc, char **argv)
 {
	int pid; /* process ID */
	pid = fork();
	if (pid == -1) 
		{
		perror("Error");
		}
	else if (pid == 0 )
		{
			printf(" In child . and his ID is  : %d.\n", getpid() ); /* for getpid() will return pid of child*/
			
		
		
		}
	else if(pid>0)
	{
			printf("This is parent process and child ID is : %d.\n",pid ); /* will return pid of child class*/
		
			printf("This is parent process and his ID is : %d.\n",getppid());	/* for getpid() will return pid of parent*/


	}
	sleep(1);


	exit(0);


}
