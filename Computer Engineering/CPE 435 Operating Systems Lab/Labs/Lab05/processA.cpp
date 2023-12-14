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
		printf("Process A Write Data: ");
		fgets(msg.msg_text, MAX, stdin);
		msg.msg_type = 1;
		msgsnd(msgid, &msg, sizeof(msg), 0);
		if(strcmp(msg.msg_text, "Exit\n") == 0)
		{
			exproc(msgid);
		}
		printf("Process A Data send: %s", msg.msg_text);
		
		msgrcv(msgid, &msg, sizeof(msg), 2, 0);
		if(strcmp(msg.msg_text, "Exit\n") == 0)
		{
			exproc(msgid);
		}
		printf("Data Received from Process B: %s", msg.msg_text);
	}
	msgctl(msgid, IPC_RMID, 0);
	return 0;
}

void exproc(int msgid)
{
	printf("\nExiting both processes\n");
	msgctl(msgid, IPC_RMID, 0);
	exit(0);
}
