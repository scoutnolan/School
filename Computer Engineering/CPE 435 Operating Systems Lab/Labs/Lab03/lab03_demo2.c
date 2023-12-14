/* 
Written By: Prawar Poudel 
This program is supposed to demonstrate the execution of dup2() function 
Please read the manual page first before jumping to run this program 
*/ 
#include <stdio.h> 
#include <unistd.h> 
#include <sys/wait.h> 
#include <stdlib.h> 
#include <fcntl.h> 
int main() 
{ 
	printf("You would expect this to go to your stdout, and it does\n"); 
	//we will create a file using open function 
	char myFileName[] = "test.txt"; 
	//lets open the file by the name of test.txt 
	int myDescriptor = open(myFileName,O_CREAT|O_RDWR|O_TRUNC,0644); 
	int id; 
	//creating a child that redirects the stdout to test.txt 
	// you can use similar functionality for '>' operator 
	if((id=fork())==0) 
	{ 
		//lets call dup2 so that out stdout (second argument) is now copied to (points to) test.txt (first argument) 
		// what this essentially means is that anything that you send to stdout will be sent to myDescriptor 
		dup2(myDescriptor,1); //1 is stdout, 0 is stdin and 2 is stderr 
		printf("You would expect this to go to your stdout, but since we called dup2, this will go to test.txt"); 
		close(myDescriptor); 
		exit(0); 
	}else 
		wait(0); 
	printf("This is also printed to the console\n"); 
	return 0; 
} 
