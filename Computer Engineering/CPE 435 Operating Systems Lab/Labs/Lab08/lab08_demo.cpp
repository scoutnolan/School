#include<stdio.h> 
#include <sys/types.h> 
#include <signal.h> 
#include <unistd.h> 
#include <cstdlib> 

//This function kills the process that makes a call to this function
 void kill_func(int killSignal) 
{ 
	printf("Received kill signal %d\n",killSignal); 
	printf("\tDying process %d\n",getpid()); 
	exit(0); 
} 
//this function prints a message and changes the function to handle the SIGINT command to kill_func() 
void myFunction(int sigVal) 
{ 
	printf("Received signal %d\n", sigVal); 
	printf("Now you can kill me..\n"); 
	signal(SIGINT,kill_func); 
} 
int main() 
{ 
	//ignore the SIGINT signal
	// .. SIGINT is ctrl+c 
	// .. SIG_IGN is signal ignore 
	// .since we ignore the signal ctrl+c, you cannot terminate this process with ctrl+c 
	signal(SIGINT,SIG_IGN); 
	//for alarm signal, call function myFunction() 
	// .. means when alarm goes off, myFunction will be called 
	signal(SIGALRM,myFunction); 
	//set alarm for 15 seconds from now 
	alarm(15); 
	printf("This gets printed as soon as alarm is called\n"); 
	//just running infinitely 
	while(1); 
}
