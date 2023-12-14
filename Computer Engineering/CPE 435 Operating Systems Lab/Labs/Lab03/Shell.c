// CPE 435 Lab 03
//
// Nolan Anderson
// 
// Create your own linux shell by writing a C/C++ program. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define MAXLINE 100 // How long each line can be
#define MAXARG 10 	// Commands, symbols and options.

int main(int argc, char* argv[]){
	while(1){ // Main shell loop
		
		int redirect = 0;
		int pipe2 = 0;
		char* temp;
		int i = 0;
		int j = 0;
		char* arg1[MAXARG];
		char* arg2[MAXARG];
		char str[MAXLINE];
		char filename[MAXLINE];
		char quit[100] = "quit";		// Character to hold quit flag
		printf("npanderson Shell: ");	// Initial shell output
		fgets(str, MAXLINE, stdin); 	// Retreive input line
		str[strlen(str) - 1] = '\0'; 	// Replace newline character with NULL
		arg1[0] = strtok(str," "); 		// Initialize, from lab document.

		if(strcmp(str, quit) == 0){		// Compare input with the quit flag, if it's the same then quit.
			return 0;
		}

		while(arg1[i] != NULL){	// Input file check
			if(arg1[i][0] == '>'){ 	// Output file check
				redirect = 1;
				arg1[i] = NULL;
				temp = strtok(NULL, ">");
				sprintf(filename, "%s", temp);
				break;
			}

			else if(arg1[i][0] == '<'){ // Check iterator for the file
				redirect = 2;
				arg1[i] = NULL;
				temp = strtok(NULL, "<");
				sprintf(filename, "%s", temp);
				break;
			}

			else if(arg1[i][0] == '|'){ // Initial check for piping
				pipe2 = 1;
				arg1[i] = NULL;
				arg2[0] = strtok(NULL, " ");
				while(arg2[j] != NULL){ 	// Second command
					if(arg2[j][0] == '>'){ 	// Output file in the pipe
						redirect = 1;
						arg2[j] = NULL;
						temp = strtok(NULL, ">");
						sprintf(filename, "%s", temp);
					break;
					}
					else if(arg2[j][0] == '<'){ // Input file in the pipe
						redirect = 2;
						arg2[j] = NULL;
						temp = strtok(NULL, "<");
						sprintf(filename, "%s", temp);
						break;
					}
					arg2[++j] = strtok(NULL, " ");
				}
				break;
			}
			else
				arg1[++i] = strtok(NULL, " ");
		}

		if(pipe2 == 1){ 		// If loop if piping is needed.
			
			int pd[2];			// Pipe dsc
			if(pipe(pd) == -1){
				exit(0);
			}

			int id = fork();
			if(id == 0){ 		// Child of the parent created, 1 - a
				dup2(pd[1],1);
				close(pd[0]);
				close(pd[1]);
				execvp(arg1[0], arg1);
				exit(0);
			}
			
			else if(id > 0){ 		// If statement for parent process
				if(fork() == 0){  	// New child of the parent process 1 - b
					dup2(pd[0],0);
					close(pd[0]);
					close(pd[1]);
					if(redirect == 1 || redirect == 2){
						int pid = fork(); 
						if(pid == 0) // Second child of the parent process 2 - b
						{
							if(redirect == 1){
								int dsc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644); // Descriptor
								dup2(dsc, 1); // Standard output  
								close(dsc);
							}
							else if(redirect == 2){
								int dsc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
								dup2(dsc, 2); // Standard input		  
								close(dsc);
							}
						}
						else
							wait(0);
					}
					execvp(arg2[0], arg2);
				}
				else{
					close(pd[0]);
					close(pd[1]);
					wait(0);
					wait(0);
				}
			}
		}

		if(pipe2 == 0){ 				// For if we do no need piping
			int pid = fork(); 
			if(pid == 0){ 				// Create a new child process
				if(redirect == 1){
					int dsc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
					dup2(dsc, 1); // Standard output
					close(dsc);
				}
				else if(redirect == 2){
					int dsc = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0644);
					dup2(dsc, 2); // Standard input
					close(dsc);
				}
				execvp(arg1[0], arg1);
			}
			else
				wait(0);
		}
	}
	return 0;
}