/* This program illustrates the death of the parent process before the child is terminated. */
/* The child process is now considered an orphan process since the parent is dead. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid;
	pid = fork();
	if (pid == 0)
	{
		printf("I am the child, my ID is %d\n", getpid());
		printf("I am the child, my parent is %d\n", getppid());
		printf("The child will now sleep for 10 seconds\n");
		sleep(10);
		printf("I am the same child with ID %d, but my parent Id is %d\n", getpid(), getppid());
	}
	else
	{
		printf("I am the parent with ID %d. My parent is %d and my child is %d\n", getpid(), getppid(), pid);
		sleep(5);
	}
}
