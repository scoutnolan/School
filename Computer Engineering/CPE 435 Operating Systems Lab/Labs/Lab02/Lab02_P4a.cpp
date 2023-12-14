// CPE 435 Lab 02 Problem 4a
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
// This file demonstrates the oprhan process.

using namespace std;

#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    int pid = fork();
    if(pid == 0)
    {
        cout << "I am the child prosess and my ID is " << getpid() << endl;
        cout << "The parent process id is " << getppid() << endl;
        sleep(20);
        cout << "I am the child process and my ID is " << getpid() << endl;
        cout << "The parent process id is " << getppid() << endl;
    }
    else
    {
        cout << "I am the parent, my process id is " << getpid() << endl;
        cout << "The parents process id is " << getppid() << endl;
    }
}
