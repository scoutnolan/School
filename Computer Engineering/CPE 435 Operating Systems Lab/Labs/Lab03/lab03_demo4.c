/* 
Written By: Prawar Poudel 
execvp runs a program that you pass as argument 
Please study about the execvp function before going to run this program 
After you understand the things, please run and watch them 
Please make sure that execvp has the right executable provided 
*/ 
#include <unistd.h> 
#include <string.h> 
#include <stdio.h> 
#include <sys/wait.h> 
int main() 
{ 
	char myArgument[100]; 
	//you can change the content of myArgument using any user typed input using gets() 
	strcpy(myArgument,"ls -a"); 
	//execvp expects the arguments to be provided as char[][] 
	//so please make sure you understand strtok before coming here 
	//we will use strtok() to break the sequence of command and argument in myArgument to convert to char[][] 
	char* myBrokenArgs[10]; //this will hold the values after we tokenize 
	printf("Starting tokenization...\n"); 
	myBrokenArgs[0] = strtok(myArgument," "); 
	int counter = 0; 
	while(myBrokenArgs[counter]!=NULL) 
	{ 
		counter+=1; 
		myBrokenArgs[counter] = strtok(NULL," "); 
	} 
	myBrokenArgs[counter] = NULL; 
	printf("\ttokenization complete....\n\nNow executing using execvp\n"); 
	printf("Following will be the output of execvp\n"); 
	printf("=======================================\n"); 
	int id; 
	//I will spawn a child that will run my execvp command 
	if((id=fork())==0) 
			execvp(myBrokenArgs[0],myBrokenArgs);
	else if(id<0) 
			printf("Failed to make child...\n"); 
	else 
	{ 
		//parent shall wait until the child is killed
		wait(0); 
		printf("=======================================\n"); printf("Completed execution\n"); 
	} 
	return 0; 
}
