#include <stdio.h> 
#include <ctype.h>
#include <string.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <stdlib.h>
#include "header.h"

void exproc(int msgid);

int main()
{
	struct msgstruct msg;
	int msgid = msgget(key, 0666 | IPC_CREAT);
	while(1)
	{
		msgrcv(msgid, &msg, sizeof(msg), 1, 0);
		if(strcmp(msg.msg_text, "Exit\n") == 0)
		{
			exproc(msgid);
		}
		printf("Data Received from Process A: %s", msg.msg_text);
		
		printf("Process B Write Data: ");
		fgets(msg.msg_text, MAX, stdin);
		msg.msg_type = 2;
		msgsnd(msgid, &msg, sizeof(msg), 0);
		if(strcmp(msg.msg_text, "Exit\n") == 0)
		{
			exproc(msgid);
		}
		printf("Process B Data send: %s", msg.msg_text);
	}
	msgctl(msgid, IPC_RMID, 0);
	return 0;
}

void exproc(int msgid)
{
	printf("\nExiting both processes.\n");
	msgctl(msgid, IPC_RMID, 0);
	exit(0);
}
