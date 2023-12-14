/* This program illustrates multiple fork operations */

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main()
{
	printf("I am the Parent\n");
	fork();
	printf("This is printed by both parent and child\n");
	fork();
	printf("This will be printed 4 times\n");
	return 0;
}
