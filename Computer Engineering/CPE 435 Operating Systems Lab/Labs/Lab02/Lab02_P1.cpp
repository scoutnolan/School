// CPE 435 Lab 02 Problem 1
//
// Nolan Anderson
// 
// 1. Write a program in C/C++ that does the following in the order given below:
//      a. Declare and initialize a variable named val (and initialize it to 0)
//      b. Call the fork system call
//      c. In the child process, add 2 to the value of val, and print it on the console screen along
//         with the pid of the child in the same statement (val and the child’s pid should be
//         printed in the same line)
//      d. In the parent process, add 5 to the value of val, and print it on the console screen
//         along with the pid of the parent process in the same statement (val and the parent’s
//         pid should be printed in the same line)
//      e. What can you conclude about the values of the variable val?

using namespace std;

#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    pid_t child1;
	child1 = fork();
    int val = 0;
    if(child1 == 0){
        cout << "Val+2 = " << val + 2 << ", and my child  PID is " << getpid() << endl;
    }
    else{
        cout << "Val+5 = " << val + 5 << ", and my parent PID is " << getpid() << endl;
    }
    return 0;
}
