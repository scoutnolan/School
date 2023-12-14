/*
Written By: Prawar Poudel 
This program is intended to showcase the use of strtok() function 
Please study about the strtok function first and compare the three outputs that you will receive here 
*/ 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
int main(int argc,char* argv[]) 
{ 
	printf("Demo Number 1\n"); 
	printf("================\n"); 
	char myString[100] = "i,want to break,this string using, both,comma and space"; 
	//following is the temporary string that I want to keep my char[] read from breaking the above char[] myString 
	//following breaks based on space character 
	char *temp; 
	temp = strtok(myString," "); //include <space> inside "" 
	while(temp!=NULL) 
	{ 
		printf("%s\n",temp); 
		temp = strtok(NULL," "); //include <space> inside "" 
	} 
	//following breaks based on comma character 
	printf("\n\nDemo Number 2\n"); 
	printf("================\n"); 
	strcpy(myString,"i,want to break,this string using, both,comma and space"); 
	temp = strtok(myString,","); //include , inside "" 
	while(temp!=NULL) 
	{ 
		printf("%s\n",temp); 
		temp = strtok(NULL,","); //include , inside "" 
	} 
	//following breaks based on space or comma character 
	printf("\n\nDemo Number 3\n"); 
	printf("================\n"); 
	strcpy(myString,"i,want to break,this string using, both,comma and space");
	temp = strtok(myString,", "); //include both space and , inside "" while(temp!=NULL) 
	while(temp!=NULL) 
	{ 
		printf("%s\n",temp); 
		temp = strtok(NULL,", "); //include both space and , inside "" 
	} 
	return 0; 
}
