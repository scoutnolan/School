// Adapted form IPC Message Queues Slides
// sender.c
// usage: ./sender <key> <type> <text>

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
	
	/* Creating a message queue */
	msid = msgget((key_t) atoi( argv[1] ), IPC_CREAT | 0666 );
	if( msid == -1 )
	{
		printf("Failed to create queue\n");
		exit(1);
	}
	
	/* Preparing a message */
	mess.mtype = atoi( argv[2] );
	strcpy( mess.mtext, argv[3] );
	
	/* Write a message into queue */
	v = msgsnd (msid, &mess, strlen( argv[3] ) + 1, 0 );
	if ( v < 0 )
	{
		printf("Message failed to send\n");
		exit(1);
	}
	printf("Message sent\n");
}
