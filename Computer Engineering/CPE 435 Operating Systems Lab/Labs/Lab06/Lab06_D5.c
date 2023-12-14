/* 
	Written By: Prawar Poudel 
	13 Feb 2018
	This is written to demonstrate the usage of Thread Local Storage using key 
*/ 
#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h> 
#define NUM_THREADS 5 
#define ARRSIZE 5 

//in this program we will use a key defined by pthread_key_t to define a key 
pthread_key_t myKey; 

void printMyVal(int myId) 
{ 
	printf("Getting specific value for thread %d using key\n",myId); int *myVal = pthread_getspecific(myKey); 
	printf("\t..The thread local value in thread id %d is %d\n",myId,*myVal); 
} 

//the argument that will be sent will be the (int) id 
void *simpleThreadFunc(void* argument) 
{ 
	int myId = (int)argument; 
	//this variable will be thread specific value that we will print from other function 
	int myVal = myId*100; 
	printf("Creating the variable ::%d that will be referred to by Key from threadid %d\n",myVal,myId); 
	if(!pthread_setspecific(myKey,(void*)&myVal)) 
	{}
	else 
	{ 
		printf("Erorr in setting specific key in thread id %d\n",myId); 
	} 
	printMyVal(myId); 
} 

int main() 
{ 
	//you can create these dynamically also 
	pthread_t myThreads[NUM_THREADS]; 
	int status = 0; 
	pthread_key_create(&myKey,NULL); 
	int i;
	for( i=0;i<NUM_THREADS;i++) 
	{ 
		printf("Creating thread no. %d, and sending ID %d\n",i,i); 
		status = pthread_create(&myThreads[i],NULL,simpleThreadFunc,(void*)i); 
		if(status) 
		{ 
			printf("Error in creating the threads: %d\n",i); 
			return -1; 
		}else 
		{ 
			printf("Successful creation of thread %d..\n",i); 
		} 
	}
	
	//this is the area that threads will run 
	//we will wait for the threads here 
	for( i=0;i<NUM_THREADS;i++) 
	{ 
		int retStatus = pthread_join(myThreads[i],NULL); 
		if(!retStatus) 
		{ 
			printf("Successful termination of thread id %d\n",i); 
		}
		else 
			printf("Well..... some problem at thread id %d, error no: %d\n",i,retStatus); 
	} 
	return 0; 
}
