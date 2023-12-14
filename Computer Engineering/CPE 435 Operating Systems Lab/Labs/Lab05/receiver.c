// Adapted form IPC Message Queues slides
// receiver.c
// usage: ./receiver <key> <type>

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

struct text_message
{
	long mtype;
	char mtext[100];
	
};

main(int argc, char *argv[])
{
	int msid, v;
	struct text_message mess;
	
	/* Get a message handle */
	msid = msgget( (key_t) atoi ( argv[1] ), 0 );
	if ( msid == -1)
	{
		printf("Queue not joined\n");
		exit(1);
	}
	
	/* Read a message of the given type */
	v = msgrcv( msid, &mess, 100, atoi( argv[2] ), IPC_NOWAIT ); // Non-blocking
	if ( v < 0 )
	{
		printf("Error receiving message\n");
		exit(1);
	}
	else
	{
		printf("%d %s\n", mess.mtype, mess.mtext);
		msgctl( msid, IPC_RMID, 0);
		exit(0);
	}
}
	
