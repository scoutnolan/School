/*
Compile with gcc Lab06_D1.c -o Lab06 -lpthread

*/

#include <pthread.h> 
#include <stdio.h> 
#define NUM_THREADS 5 

void* printHello(void *threadId) 
{ 
	printf("\n%d:Hello World!\n",threadId); 
	pthread_exit(NULL); 
} 
int main() 
{ 
	pthread_t threads[NUM_THREADS]; 
	int rc,t; 
	for(t=0;t<NUM_THREADS;t++) 
	{ 
		printf("Creating thread %d\n",t); 
		rc = pthread_create(&threads[t],NULL,printHello,(void*)t); 
		if(rc)
		{ 
			printf("ERROR:Return Code from pthread_create() is %d\n",rc); 
		} 
	} 
	pthread_exit(NULL); 
}
