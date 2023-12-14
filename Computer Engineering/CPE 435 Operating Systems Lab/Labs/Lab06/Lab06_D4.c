/* 
	Written By: Prawar Poudel 
	13 Feb 2018 
	This is written to demonstrate the usage of Thread Local Storage Here using identifier __thread , we have made myVal and myArr[] thread local 
*/ 
#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h> 
#define NUM_THREADS 5 
#define ARRSIZE 5 
//this value is a global variable, 
// but we will store it as thread local, meaning while it is still global the value will can be modified such that the modified value is thread specific 
__thread int myVal; 
__thread int myArr[ARRSIZE]; 

void printMyVal(int id) 
{ 
	int i;
	printf("My value myVal from thread %d is %d\n", id,myVal); 
	printf("My arr value are\n"); 
	for( i=0;i<ARRSIZE;i++) 
	{ 
		printf("%dthe element is %d\n",i,myArr[i]); 
	}
} 

//the argument that will be sent will be the (int) id 
void *simpleThreadFunc(void* argument) 
{ 
	int i;
	int myId = (int)argument; 
	printf("My Id is %d\n",myId); 
	//just setting some thread specific value to the variable 
	myVal = myId*100; 
	for( i=0;i<5;i++) 
		myArr[i] = (myId*100+i); 
	
	printMyVal(myId); 
} 

int main() 
{ 
	//you can create these dynamically also 
	pthread_t myThreads[NUM_THREADS]; 
	int status = 0;
	int i;
	for( i=0;i<NUM_THREADS;i++) 
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
