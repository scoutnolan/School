// gcc serial.c -o serial -std=c99 -lm
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <sys/time.h>

#define UPPER 1
#define LOWER 0

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

struct timeval tv1,tv2;
#define TIMER_CLEAR     (tv1.tv_sec = tv1.tv_usec = tv2.tv_sec = tv2.tv_usec = 0)
#define TIMER_START     gettimeofday(&tv1, (struct timezone*)0)
#define TIMER_ELAPSED   (double) (tv2.tv_usec-tv1.tv_usec)/1000000.0+(tv2.tv_sec-tv1.tv_sec)
#define TIMER_STOP      gettimeofday(&tv2, (struct timezone*)0)

// Get width function
double getW(double upper, double lower, int num)
{
    double width = ((upper - lower) / num);
    return width;
}

// Get height function
double getH(double width, int i)
{
	double x = width * i;
    double height = sqrt(1 - pow(x, 2));
    return height;
}

int main(int argc, char* argv[])
{
    TIMER_CLEAR;
    TIMER_START;
    // Error checking
	if(argc != 2)
	{
		printf("Error.. Wrong number of input arguments.\nTerminating program...\n");
		return 1;
	}
	unsigned long rectangles = atoi(argv[1]);
	if(rectangles < 0)
	{
		printf("Error.. Input can not be negative.\nTerminating program...\n");
		return -1;
	}

    // Perform math operation
	double sum = 0;
    double width = getW(UPPER, LOWER, rectangles);
    for(int i = 0; i < rectangles; i++)
    {
        sum += width * getH(width, i);
    }
    sum *= 4;

    // Output solution and ET.
    printf("Sum    = %1.9g\n", sum);
    printf("Actual = %1.9g\n", M_PI);
    double error = (1 - M_PI / sum);
    printf("Error  = %.1e\n", error);
    TIMER_STOP;
    printf("Time elapsed = %f seconds\n", TIMER_ELAPSED);
    return 0;
}