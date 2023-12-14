/* 
Written By: Prawar Poudel
This program demonstrates the use of pipe() function in C 
Please man pipe and have understanding before going through this code 
Pipe passes information from one process to another, similar to water-pipes there is a read-end and a write-end of pipe 
*/ 
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <sys/wait.h> 
int main() 
{ 
	int myPipingDescriptors[2]; 
	if(pipe(myPipingDescriptors)==-1) 
	{ 
		printf("Error in calling the piping function\n"); 
		exit(0); 
	} 
	//at this point two pipe ends are created 
	// one is the read end and other is write end 
	// [0] will be the read end, [1] will be the write end 
	//now lets fork two process where one will make use of the read end and other will make 
	// use of write end 
	// they can communicate this way through the pipe 
	int id; 
	if((id=fork())==0) 
	{ 
		dup2(myPipingDescriptors[1],1); //second argument 1 is stdout 
		close(myPipingDescriptors[0]); //read end is unused to lets close it 
		//this following statement will not be printed since we have copied the stdout to write end of pipe 
		printf("I am child, and sending this message.\n"); 
		exit(0); 
	}else if (id>0) 
	{ 
		wait(0); 
		char myRead[100]; 
		//basically what's written to the write-end of pipe stays there until we read the read-end of pipe 
		read(myPipingDescriptors[0],myRead,37); 
		printf("I am parent. I read following statement\n\t%s\n",myRead); close(myPipingDescriptors[1]); 
	}else 
	{
		printf("Failed to fork so terminating the process\n"); 
		exit(-1); 
	} 
	close(myPipingDescriptors[0]); 
	close(myPipingDescriptors[1]); 
	return 0; 
} 
