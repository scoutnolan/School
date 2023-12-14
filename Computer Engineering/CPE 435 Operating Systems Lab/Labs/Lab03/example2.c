#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>

int main()
{
	char *cmd[] = {"who", "ls", "date"};
	int i;
	printf("0=who, 1=ls, 2=date :");
	scanf("%d", &i);
	execlp(cmd[i], cmd[i], 0);
	printf("command not found\n"); /*exec failed*/
}
