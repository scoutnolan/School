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

	if ((id = shmget(KEY, MSIZ, 0)) < 0)
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
	
	while(ctrl->flag == 0);
	printf("Begin Process B\n");

	// Loop for more than one value
	do
	{
		ctrl->flag = 0;
		while(ctrl->flag == 0);
		ctrl->sum = ctrl->value1 + ctrl->value2; 
		printf("Sum of %f and %f = %f\n", ctrl->value1, ctrl->value2, ctrl->sum);
	}while(ctrl->flag == 1);
	
	ctrl->flag = 0; // Process A flag.
	while(ctrl->flag != -1); // Wait for process A flag to be -1.
	shmdt(ctrl);
	exit(0);
}
