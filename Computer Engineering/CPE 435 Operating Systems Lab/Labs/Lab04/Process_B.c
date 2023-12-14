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

#include "line.h"


/*
	
	Process B can change the contents of the shared memory that Process A is using
	./ProcessB <char> <int>
	
*/

main(int argc, char *argv[])
{  
    	int  id  ;
    	struct info *ctrl;
    
	if (argc < 3) 
	{
		//error…;
		exit(3);
	}
	// get the id of the already created shared memory segment
	// .. function to create is same as getting id of the already created shared memory segment
	if ( (id = shmget( key,MSIZ, 0 )) < 0 )
    	{
		//error … ; 
		exit(1) ; 
	}
   
  	// attach a local pointer to the shared memory
  	 ctrl = (struct info *) shmat( id, 0, 0);
	if ( ctrl <= (struct info *) (0) )
    	{
		//error … ; 
		exit(1) ;  
	}
	
	/* copy command line data to shared memory  */
   	ctrl->c = argv[1][0] ;
   	ctrl->length = atoi(argv[2]);

   
   	//detach the pointer from the shared memory 
   	// .. we do not need to delete here, can be done in either of the process
   	shmdt(ctrl);
   	exit(0);
 }
