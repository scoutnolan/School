// ***********************************************************************
// ***********************************************************************
// **
// **  USE THIS HEADER FILE AS IS.  
// **  DO NOT MODIFY THIS FILE
// ** 
// ***********************************************************************
// ***********************************************************************

// #######################################################################
// the first two # statements allow for this header file
// to be included one time only.  These statements are
// necessary since all .cpp files require the 
// information in this header file, and therefore it is included
// in each .cpp file
// #######################################################################

#ifndef P08_H
#define P08_H

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

// structure declarations - using a Hierarchical format.
struct Name
{
       string title;  // title of the employee, Dr., Mr., Mrs., or Miss
       string first;  // first name of the employee
       string last;   // last name of the employee
};
struct Address
{
       string street; 		// street number and name of the employee's address
       string cityState;  	// city state combination of employee's address
       string zipCode;    	// 9 digit zip code of employee #####-####
};
struct Phone
{
       string home;       // home phone number ###-###-####
       string cell;       // home cell number ###-###-####
       string work;       // home work number ###-###-####
};
struct DirectoryInfo
{
       Name employeeName;    	// structure holding employee name
       Address employeeAddress; // structure holding employee address
       Phone employeePhone;     // structure holding employee phone #'s
};
// 12 * in a constant for header lines
const string STAR = "************";  // line delineater for output file

// **********************************************************************
// **  The following function prototypes are ones for functions that
// **  students must write the code.  The function definitions 
// **  for these prototypes must be written in the file Project_09.cpp
// **********************************************************************

// Function Prototypes
void OpenInputFile(ifstream&);  // open input file of jumbled directory
void OpenOutputFile(ofstream&);  // open output file for new directory 

// read the jumbled information for one employee
bool ReadInformation(ifstream&, DirectoryInfo&); 

// Print the information correctly to the new directory
void PrintInformation(ofstream&, DirectoryInfo );

#endif
