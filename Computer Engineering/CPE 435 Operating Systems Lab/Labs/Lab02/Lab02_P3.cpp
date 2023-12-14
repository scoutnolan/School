// CPE 435 Lab 02 Problem 3
//
// Nolan Anderson
// 
// 3. Write a C/C++  program which creates n child processes and prints their process id. The n
//    number of processes must be an even number and passed as input to the program by the
//    user. If n is not even a message should indicate that the number is odd and terminates the
//    program. Please make sure that your implementation has one parent process which creates n
//    child processes.

using namespace std;

#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char * argv[])
{
    int num;
    cout << "Enter an even number" << endl;
    cin >> num;
    if(num % 2 == 0)
    {
        pid_t child;
        for(int i = 0; i < num; i++)
        {
            if(fork() == 0)
            {
                cout << "Child ID " << getpid() << " Parent ID " << getppid() << endl;
                exit(0);
            }
        }
        for(int i = 0; i <= num; i++)
            wait(NULL);
    }
    else
    {
        cout << "The number entered is not even. Terminating Program. " << endl;
        exit(0);
    }
    return 0;
}