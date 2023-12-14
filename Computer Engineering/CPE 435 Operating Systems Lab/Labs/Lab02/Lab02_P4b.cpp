// CPE 435 Lab 02 Problem 4b
//
// Nolan Anderson
// 
// 4. Write a C/C++ program (or programs) that demonstrates the following concepts:
//      a. Orphan process
//      b. Zombie process
//      c. Sleeping beauty process
//      d. Verify that you actually achieved all the three states mentioned above by using
//         the terminal. Put a screenshot of the process table in your report. Each program
//         should print out their pid, which should be visible in the process table.
//
// This file demonstrates the Zombie Process

using namespace std;

#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    if(fork() > 0)
    {
        cout << "Child " << getpid() << endl;
        cout << "Parent " << getppid() << endl;
        sleep(50);
    }
}