#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "header.h"

int main(void)
{
	int id;
	struct info* ctrl;

	if ((id = shmget(KEY, MSIZ, IPC_CREAT | 0666)) < 0)
	{
		printf("ERROR! Terminating program \n");
		exit(1);
	}

	ctrl = (struct info*) shmat(id, 0, 0);

	if (ctrl <= (struct info*)(0))
	{
		printf("ERROR! Terminating program \n");
		exit(2);
	}

	printf("Begin Process A\n");

	do{
		printf("Set Value 1 : ");
		scanf("%f", &ctrl->value1);
		printf("Set Value 2 : ");
		scanf("%f", &ctrl->value2);	
		printf("Set Continue Flag : ");
		scanf("%d", &ctrl->flag);
	}while(ctrl->flag == 1);

	fflush(stdout);

	while(ctrl->flag == -1); // Here we need to wait for the flag to be set by proccess 1. 

	ctrl->flag = -1;
	printf("Setting flag to %i\n", ctrl->flag);
	printf("Terminating program...\n");
	fflush(stdout);
	shmdt(ctrl);
	shmctl(id,IPC_RMID,NULL);
	exit(0);
}
