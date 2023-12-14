// gcc parallel.c -o parallel -lm -std=c99 -lpthread
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>
#define LENGTH 1

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

double sum, dx;
unsigned long threads, rectangles;
pthread_mutex_t myMutex;
pthread_key_t myKey;

struct timeval tv1,tv2;
#define TIMER_CLEAR     (tv1.tv_sec = tv1.tv_usec = tv2.tv_sec = tv2.tv_usec = 0)
#define TIMER_START     gettimeofday(&tv1, (struct timezone*)0)
#define TIMER_ELAPSED   (double) (tv2.tv_usec-tv1.tv_usec)/1000000.0+(tv2.tv_sec-tv1.tv_sec)
#define TIMER_STOP      gettimeofday(&tv2, (struct timezone*)0)

double f(double inval)
{
	return(sqrt(1 - pow(inval, 2)));
}

void* updateSum(void* arg)
{
	double x, temp;
	int myStart = *(int*) arg;
	// int myStart = *(int*) arg;
	temp = 0; // make sure the sum is 0 for each thread call
	for (unsigned long i = myStart; i < rectangles; i += threads)
	{
		x = dx * i;
		temp += dx * f(x);
	}
	pthread_mutex_lock(&myMutex);
	sum += temp;
	pthread_mutex_unlock(&myMutex);
	return(NULL);
}

int main(int argc, char* argv[])
{
	TIMER_CLEAR;
    TIMER_START;
	// Error checking.
	if(argc != 3)
	{
		printf("Error.. Wrong amount of input arguments.\nTerminating program...\n");
		return 1;
	}
	
	// Intitial calculation
	sum = 0;
	int i;
	rectangles = atoi(argv[1]);
	threads = atoi(argv[2]);
	printf("Number of rectangles = %ld\n", rectangles);
	printf("Number of threads    = %ld\n", threads);
	pthread_t myThreads[threads];
	dx = LENGTH / (double)rectangles; // width of 1 rectangle
	pthread_key_create(&myKey, NULL);
	int start[threads];

	if(rectangles < 0)
	{
		printf("Error.. Input can not be negative.\nTerminating program...\n");
		return 2;
	}

	// pthread initialize error checking
	if(pthread_mutex_init(&myMutex, NULL))
	{
		printf("Error.. Cannot init mutex lock.\nTerminating program...\n");
		return 3;
	}

	int status = 0;
	// Thread creation check
    for(i = 0; i < threads; i++)
	{
		start[i] = i;
		void* ptr = start + start[i];
		status = pthread_create(&myThreads[i], NULL, updateSum, &start[i]);
		if(status)
		{
			printf("Error.. Could not create the threads.\nTerminating program...\n");
			return 4;
		}
	}

	for(i = 0; i < threads; i++)
	{
		int retStatus = pthread_join(myThreads[i], NULL);
		if(retStatus)
		{
			printf("Error.. Problem at thread id %d.\nError number:%d\n", i, retStatus);
		}	
	}
    sum *= 4;
	TIMER_STOP;

	printf("Sum    = %1.9g\n", sum);
    printf("Actual = %1.9g\n", M_PI);
    double error = (1 - M_PI / sum);
    printf("Error  = %.1e\n", error);
    printf("Time elapsed = %f seconds\n", TIMER_ELAPSED);
    return 0;
}