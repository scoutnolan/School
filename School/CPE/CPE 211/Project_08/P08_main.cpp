// **********************************************
// **
// **  USE THIS PROGRAM AS IS
// **  DO NOT MODIFY IT IN ANY WAY
// **
// **********************************************

// ***********************************************************************
// ***********************************************************************
// Project 08 - Directory ReOrganizer   

// This program uses structures to hold information read from a jumbled
// directory file.  This information is then written in the desired format
// into a new directory (output file)
// ***********************************************************************
// ***********************************************************************

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "P08.h"   // prototypes, constants and structure declarations for project 9

using namespace std;
int main()
{
    // varialbe declarations
    ifstream inFile;        // jumbled directory file
    ofstream outFile;       // New directory file
    DirectoryInfo info;     // structured information for one employee
    string line;            // name of the directory read from input file
       
    // associate the input file stream variable with the input file 
    // that contains the jumbled diretory.  All aspects of the association
    // are to take place in the funcution
    OpenInputFile(inFile);
    // set up the output file stream variable with the output file entered.
    OpenOutputFile(outFile);  
    
    // read the directory name from the jumbled input file and write this
    // name to the new directory file
    getline(inFile, line);
	if (!inFile)
	{
	    cout << STAR << STAR << STAR << STAR << endl;
	    cout << "===>  Reading the directory title failed.\n";
		cout << "===>  Therefore, the input file is empty.\n";
		cout << "===>  No information written to the output file\n";
	    cout  << STAR << STAR << STAR << STAR << endl<< endl;
		return 1;
	}
	//Output the directory title and then row of asterisks
    outFile << line << endl;
	outFile << STAR << STAR << STAR << STAR << STAR << endl;
    
    // Read the information for each employee and then print it to the output
    // file.  continue in a loop until the end of the jumbled directory
    // is reached.
    while(ReadInformation(inFile, info))  // loop thoruh each employees info
    {
        PrintInformation(outFile, info);
    }
    // close the open file streams.  needed for output file to ensure that
    // all information in the buffer is written to the file.
    inFile.close();
    outFile.close();
	return 0;			// Done!
} // End main()

