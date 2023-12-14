#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int serialnum;
	int pid;
    printf("I am the parent\n");
    for(int i = 0; i <= 10; i++)
    {
        if(fork() == 0)
        {
            serialnum = i;
            printf("I am the child, my ID is %d, my serial num is %d and my parents ID is %d\n", getpid(), serialnum, getppid());
            exit(0);
        }
    }
    for(int i = 0; i <= 10; i++)
    {
        sleep(NULL);
    }
}
