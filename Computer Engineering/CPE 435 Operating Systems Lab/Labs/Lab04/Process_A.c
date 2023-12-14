/***********************************************************************************
		Code  Inherited from Anon
		Massively Modified by Prawar Poudel, 3 Feb 2020 (pp0030@uah.edu)
		Modified by Noah Eid, 30 Jan 2021 (nae0005@uah.edu)
************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#include "line.h"

/*
	Process A creates a shared memory segment
	Process A attaches a pointer to the shared memory segment created
	.. then it writes an integer value and a character value to it
	Process A will then print that character every 4 seconds to terminal
	.. a number of times

	Process B will can also access the shared memory segment and change
	.. the character being printed

	After the printing operation is done, Process A will detach and delete the shared memory segment
	
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
    if ( (ctrl = (struct info *) shmat( id, 0, 0)) <= (struct info *) (0) )
	{
		//error … ; 
     	printf("error 2\n");
		exit(1) ;  
	}

	// put some initial data in the shared memory so that we will just print the things before ProcessB is run
	ctrl->c = 'a';
	ctrl->length = 10;

	// print line every 4 seconds
	for (i = 0 ; i <ctrl->length ; i++ )
	{
		 putchar (ctrl->c);
		 putchar ('\n');
		 sleep(4);
	}

	//now detach the pointer from the shared memory
	shmdt(ctrl);
	//let us delete the shared memory
	shmctl(id,IPC_RMID,NULL);
	
	//job done
}

