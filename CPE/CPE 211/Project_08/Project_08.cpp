// ****************************
// Project Title: Project 08
// Project File: Project_08.cpp
// Name: Nolan Anderson
// Course Section CPE-211-01
// Lab Section: 2
// Due Date: 11/1/2019
// program description: Uses functions and structures to output information previously scrambled to an output file.
// What the program does
// ****************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "P08.h"
#include <climits>
#include <cstdlib>
#include <cctype>

// SOLUTION PATHS //

///home/work/cpe211/Executables/Project_08/Project_08_solution
///home/work/cpe211data/Project_08/CompareSolution.bash Project_08.cpp

// ******************** PARAMETER DECLARATIONS ********************* //
// Function Prototypes
void OpenInputFile(ifstream&);  // open input file of jumbled directory
void OpenOutputFile(ofstream&);  // open output file for new directory
bool ReadInformation(ifstream&, DirectoryInfo&); // read information from the file 2 parameters.
void PrintInformation(ofstream&, DirectoryInfo ); // output information to out file

// ********** OPEN INPUT FILE FUNCTION ********** //
void OpenInputFile(ifstream& input)
{
    string inFile;
    cout << endl;
    cout << "Enter in the name of the input file (ctrl-c to exit): ";
    cin >> inFile;
    cout << inFile;
    input.open(inFile.c_str());
    while (input.fail()) // if the file does not open then ask for a new input file until a good one is submitted.
    {
        input.clear();
        cout << endl << endl;
        cout << string(60,'*') << endl;
        cout << "==> " << inFile << " is an invalid file!! Try Again." << endl;
        cout << string(60,'*') << endl;
        cout << endl;
        cout << "Enter in the name of the input file (ctrl-c to exit): ";
        cin >> inFile;
        cout << inFile;
        input.open(inFile.c_str());
    }
}

// ********** OPEN OUTPUT FILE FUNCTION ********** //

void OpenOutputFile(ofstream& output)
{
    //string& outFile
    string outFile;
    cout << endl << endl <<  "Enter in the name of the output file: ";
    cin >> outFile;
    cout << outFile;
    output.open(outFile.c_str());
    while (output.fail()) // if the output file fails to open or is not a file, then ask for a new file until a good one is entered.
    {
        output.clear(); // clears the output stream so a new file can be entered.
        cout << endl << endl;
        cout << string(60,'*') << endl;
        cout << "==> " << outFile << " is an invalid file!! Try Again." << endl;
        cout << string(60,'*') << endl;
        cout << endl;
        cout << "Enter in the name of the output file (ctrl-c to exit): ";
        cin >> outFile;
        cout << outFile;
        output.open(outFile.c_str());
    }
    cout << endl << endl;
}

// *********** READ INFORMATION FUNCTION *************** //

bool ReadInformation(ifstream& input, DirectoryInfo& person)
{ // DirectoryInfo& person - grabs the directory info and assigns it to the person variable get the first line.
    static int count = 0;
    input >> person.employeeName.title; // input for the first title variable
    if (input.eof() == true) // checks to see if the title is there and end of file. if it is not there, then terminate the program.
    {
        if (count == 0)
        {
            cout << string(60,'*') << endl;
            cout << "===>  Reading the title of the first employee failed." << endl;
            cout << "===>  The input file contained a directory title only"  << endl;
            cout << "===>  No employee information was written to the output file" << endl;
            cout << string(60,'*') << endl << endl;
            return false;
        }
        return false;
    }
    input.ignore(INT_MAX,'\n'); // ignores the pervious line delimetter.
    getline(input,person.employeeAddress.street,'\n'); // Street address
    input >> person.employeePhone.cell; // Cell phone
    input.ignore(INT_MAX,'\n');
    input >> person.employeeName.last; // Last name
    input.ignore(INT_MAX,'\n');
    input >> person.employeePhone.home; // Home phone
    input.ignore(INT_MAX,'\n');
    getline(input, person.employeeAddress.cityState,'\n'); // city state
    input >> person.employeeName.first; // first name
    input.ignore(INT_MAX,'\n');
    input >> person.employeePhone.work; // Work phone
    input.ignore(INT_MAX,'\n');
    input >> person.employeeAddress.zipCode; // Zip code
    input.ignore(INT_MAX,'\n');
    count ++;
    if (input)
    {
        return true;
    }
    
}

// ********** PRINT INFORMATION FUNCTION ********* //

void PrintInformation(ofstream& outfile, DirectoryInfo person)
{ // Function outputs the information found in ReadInformation function to the output file that was opened in OpenOutputFile.
    static int num = 1;
    outfile << "                         Employee #" << num << endl;                               // outputs employee number
    outfile << person.employeeName.title << " " << person.employeeName.first << " " << person.employeeName.last << endl; // outputs the name of the employee
    outfile << person.employeeAddress.street << endl;                                              // outputs the street address
    outfile << person.employeeAddress.cityState << ", " << person.employeeAddress.zipCode << endl; // outputs city, state, and zip code.
    outfile << person.employeePhone.home << "(H)" << endl << person.employeePhone.cell << "(C)" << endl << person.employeePhone.work << "(W)" << endl;                                                                                      // phone number output
    outfile << string(60,'*') << endl;
    num ++;
}

