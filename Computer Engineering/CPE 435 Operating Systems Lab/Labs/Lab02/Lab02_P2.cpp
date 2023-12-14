// CPE 435 Lab 02 Problem 2
//
// Nolan Anderson
// 
// 2. Write a  C/C++ programming that does the following:
//      a. Create a new process child1
//      b. The parent (of child1) should print its id and wait for the termination of the child1
//         process
//      c. The child1 process should call a function that subtracts two numbers passed as
//         arguments and print the result on the console screen along with the pid of the process
//         that is printing
//      d. The child1 process should create a new child process (child2)
//      e. The child2 process should call a function that adds two numbers passed as
//         arguments  and print the result along with its pid while child1 waits
//      f. Control should then come back to the first child process child1 that now should call a
//         function that multiplies two numbers passed as arguments and print the result and pid
//         of the printing process to the console and then terminate
//      g. The waiting parent process should now resume and terminate the program
//      h. Note: arguments to functions may be hard coded or taken in as user input

using namespace std;

#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void subfunc(int one, int two);
void addfunc(int one, int two);
void mulfunc(int one, int two);

int main(int argc, char * argv[])
{
    int one = 1; int two = 2;
    pid_t child1;
	cout << "The pid of the parent is " << getpid() << endl;
	child1 = fork();        // Create the child process.
	if (child1 == 0) 
	{
        subfunc(one, two);  // We are the child so do the subtract function. 
        pid_t child2;       // Create a second child.
        child2 = fork();    // Fork a process
        if(child2 == 0)     // If we are the second child...
        {
            addfunc(one, two);  // Since we are child two, we will now add. 
            exit(0);
        }
        else
        {
            wait(0);
        }
        mulfunc(one, two);  // Now that child 2 is done, we will now tell child 1 to multiply. 
        exit(0); // Now child 1 is done. 
	}
    else // Now the control goes back to the parent. 
    {
        wait(0);
    }
	exit(0);
    return 0;
}

void subfunc(int one, int two){
    cout << "Subtraction - The result is " << two - one << " and the id is " << getpid() << endl;
}

void addfunc(int one, int two){
    cout << "Addition - The result is " << two + one << " and the id is " << getpid() << endl;
}

void mulfunc(int one, int two){
    cout << "Multiplication - The result is " << two * one << " and the id is " << getpid() << endl;
}