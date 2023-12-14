/* This program illustrates the use of fork */

#include <stdio.h>
#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
	int x;
	x = 0;
	fork();
	x++;
	// This should be printed twice, once by the parent and once by the child
	cout << "I am process "<< getpid() << " and my x is " << x << endl;
	return 0;
}
