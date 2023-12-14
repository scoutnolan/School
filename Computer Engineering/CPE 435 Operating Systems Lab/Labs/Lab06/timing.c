#include <stdio.h>
#include <stdlib.h>


#define TIMER_CLEAR     (tv1.tv_sec = tv1.tv_usec = tv2.tv_sec = tv2.tv_usec = 0)
#define TIMER_START     gettimeofday(&tv1, (struct timezone*)0)
#define TIMER_ELAPSED   (double) (tv2.tv_usec-tv1.tv_usec)/1000000.0+(tv2.tv_sec-tv1.tv_sec)
#define TIMER_STOP      gettimeofday(&tv2, (struct timezone*)0)
struct timeval tv1,tv2;


int main(int argc, char* argv[])
{
	int i;
	TIMER_CLEAR;
	TIMER_START;
	// Call to function that you want to time
	// example
	sleep(5); //Timer will give us ~5 seconds
	TIMER_STOP;
	printf("Time elapsed = %f seconds\n", TIMER_ELAPSED);


	return 0;
}