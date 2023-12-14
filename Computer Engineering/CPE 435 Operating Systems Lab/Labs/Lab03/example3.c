#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
	char *cmd[] = {"who", "ls", "date", "notacommand"};
	int i;
	while(1)
	{
		printf("0=who, 1=ls, 2=date, 3=notacommand :");
		scanf("%d", &i);
		if(fork() == 0)
		{
			execlp(cmd[i], cmd[i], 0);	// If execlp runs correctly, control 
							// is transfer to the new program
			printf("command not found\n");  // exec failed
			exit(1);
		}
		else
		{
			// Parent waits for child process to complete
			wait(0);
		}
	}
}
