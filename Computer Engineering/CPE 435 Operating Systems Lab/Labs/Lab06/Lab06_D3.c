/* 
	Written By: Prawar Poudel 
	13 Feb 2018 
	This is written to demonstrate simple creation and waiting for pthread to terminate 
*/ 
#include <pthread.h> 
#include <stdio.h> 
#include <unistd.h> 
#define NUM_THREADS 100 
int mutexProtectedGlobalVariable; 
int unprotectedProtectedGlobalVariable; 
pthread_mutex_t myMutex;
 
//this function will update the value without any protection 
void *unprotectedThreadFunc(void* argument)
{ 
	int i;
	for( i=0;i<10000;i++) unprotectedProtectedGlobalVariable++; } 
	
//this function will update the value without any protection 
void *protectedThreadFunc(void* argument) 
{ 
	int i;
	pthread_mutex_lock (&myMutex); 
	for( i=0;i<10000;i++) mutexProtectedGlobalVariable++; pthread_mutex_unlock (&myMutex); 
} 

int main() 
{ 
	mutexProtectedGlobalVariable = 0; 
	unprotectedProtectedGlobalVariable = 0; 
	int i;
	
	//you can create these dynamically also 
	pthread_t myThreads[NUM_THREADS]; 
	int status = 0; 
	printf("Calling unprotected set of threads\n"); 
	
	//first set of five threads will call a function that will update the variable unprotected 
	for(i=0;i<NUM_THREADS;i++) 
	{ 
		status = pthread_create(&myThreads[i],NULL,unprotectedThreadFunc, (void*)i); 
		if(status) 
		{ 
			printf("Error in creating the threads: %d\n",i); 
			return -1; 
		} 
	} 
	
	//this is the area that threads will run 
	//we will wait for the threads here 
	for(i=0;i<NUM_THREADS;i++) 
	{ 
		int retStatus = pthread_join(myThreads[i],NULL); 
		if(retStatus) 
		{ 
			printf("Well..... some problem at thread id %d, error no: %d\n",i,retStatus); 
		} 
	} 
	printf("Unprotected sum is %d\n", unprotectedProtectedGlobalVariable); printf("\t\t...end of unprotected set of threads\n"); 
	printf("Calling protected set of threads\n"); 
	pthread_mutex_init(&myMutex, NULL); 
	
	//next set of five threads will call a function that will update the variable protected 
	for(i=0;i<NUM_THREADS;i++) 
	{
		status = pthread_create(&myThreads[i],NULL,protectedThreadFunc, (void*)i); 
		if(status) 
		{ 
			printf("Error in creating the threads: %d\n",i); 
			return -1; 
		} 
	} 
	
	//this is the area that threads will run 
	//we will wait for the threads here 
	for(i=0;i<NUM_THREADS;i++) 
	{ 
		int retStatus = pthread_join(myThreads[i],NULL); 
		if(retStatus) 
		{ 
			printf("Well..... some problem at thread id %d, error no: %d\n",i,retStatus); 
		} 
	} 
	pthread_mutex_destroy(&myMutex); 
	printf("Protected sum is %d \n", mutexProtectedGlobalVariable); printf("\t\t...end of unprotected set of threads\n"); 
	return 0; 
} 
