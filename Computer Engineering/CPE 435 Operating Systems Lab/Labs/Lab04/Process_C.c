/***********************************************************************************
		Code  Inherited from Anon
		Massively Modified by Prawar Poudel, 3 Feb 2020 (pp0030@uah.edu)
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "header.h"

/*
	Process C creates a shared memory segment
	Process C attaches a pointer to the shared memory segment created
	.. then it writes an integer value and a character value to it
	.. it prints the character value for the integer number of times
	.. then it waits on Process D to update the value of integer and the character
	.. .. this will be indicated by the flag value being set to 1 by Process D 
	.. after the same printing operation is done, Process C will detach and delete the shared memory segment
	
*/
main(void)
{  
    int  i, id  ;
    struct info *ctrl;
    
	// create the shared memory segment 
	// .. id is the file identifier of the shared memory segment 
	// .. if the key is shared, any process can attach to this shared memory segment 
	// .. 0666 is the file permission for the shared memory segment
    if ( (id = shmget( key,MSIZ,IPC_CREAT | 0666) ) < 0 )
    {
	   //error…; 
	   printf("error 1\n");
	   exit(1) ; 
    }

	// attach a local pointer to the shared memory segment created
	// .. exit if fails
    if ( (ctrl = (struct info *) shmat( id, 0, 0)) <= (struct info *) (0) ){
    //error … ; 
     	printf("error 2\n");
	exit(1) ;  }

	// put some initial data in the shared memory so that we will just print the things before Process D is run
	ctrl->c = 'a';
	ctrl->length = 10;
	ctrl->flag = 0;

	// print the character ctrl->c for ctrl->length times in a single line
		for (i = 0 ; i <ctrl->length ; i++ )
		{
			 putchar (ctrl->c);
			 putchar (' ');
		}
 putchar('\n');
	
	// flushing stdout just in case
	fflush(stdout);
	
	// signal Process D that Process C is ready for next round, which will be printed below
	ctrl->flag = 2;
	
	// wait for the flag to be set in processB to 1
	// .. flag is 0 right now
	// .. once processB starts to run, it will set the flag to 1
	while(ctrl->flag!=1);
	
	
	// print the character ctrl->c for ctrl->length times in a single line 
		for (i = 0 ; i <ctrl->length ; i++ )
		{
			 putchar (ctrl->c);
			 putchar (' ');
		}
	putchar ('\n');
	// flushing stdout just in case
	fflush(stdout);
	
	//now detach the pointer from the shared memory
	shmdt(ctrl);
	//let us delete the shared memory
	shmctl(id,IPC_RMID,NULL);
	
	//job done
}

