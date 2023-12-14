/* 
	Written By: Prawar Poudel 
	13 Feb 2018 
	This is written to demonstrate simple creation and waiting for pthread to terminate 
*/ 
#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h> 
#define NUM_THREADS 5 

//the argument that will be sent will be the (int) id 
void *simpleThreadFunc(void* argument) 
{ 
	int myId = (int)argument; 
	printf("My Id is %d\n",myId); 
	int a = 0; 
}

int main() 
{ 
	//you can create these dynamically also 
	pthread_t myThreads[NUM_THREADS]; 
	int status = 0; 
	int i;
	for(i=0;i<NUM_THREADS;i++) 
	{ 
		printf("Creating thread no. %d, and sending ID %d\n",i,i); 
		status = pthread_create(&myThreads[i],NULL,simpleThreadFunc,(void*)i); if(status) 
	{ 
		printf("Error in creating the threads: %d\n",i); 
		return -1; 
	}else 
	{ 
		printf("Successful creation of thread..\n"); 
	} 
	} 
	//this is the area that threads will run 
	//we will wait for the threads here 
	for(i=0;i<NUM_THREADS;i++) 
	{ 
		int retStatus = pthread_join(myThreads[i],NULL); 
		if(!retStatus) 
		{ 
			printf("Successful termination of thread id %d\n",i); 
		}else 
			printf("Well..... some problem at thread id %d, error no: %d\n",i,retStatus); 
	} 
	return 0; 
} 
