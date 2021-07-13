// ****************************
// Project Title: Project 04
// Project File: Project_04.cpp
// Name: Nolan Anderson
// Course Section CPE-211-01
// Lab Section: 2
// Due Date: 9/04/2019
// program description: takes input from a user file and splits the lines at special characters
// Also tests the status of the file and if it has been reached.
// ****************************
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <climits>
using namespace std;

int main()
{
    
	// Declaring Variables
	
	string filename;
	ifstream InFile;
	cout << "Enter name of the input file: " << endl;
    cin >> filename;
    InFile.open(filename.c_str());
    // Delcaring part 1
    char special_char1;
    string line4;
	string line1;
    string line1_p1;
    float len_p1;
    string line1_p2;
    string line3;
    float len_line1;
    float percent;
    // Declaring part 2
    char special_char2;
    string line2;
    string line2_p1;
    string line2_p2;
    string line2_p3;
    
    
	
    
    
// ****************** Provided input ****************** // 





// Tests the status of the file stream.
    if (InFile.fail())
    {
        cout << string(15,'*') << " File Open Error" << string(15,'*') << endl;
        cout << "==> Input file failed to open properly!!\n";
        cout << "==> Attempted to open file: " << filename << endl;
        cout << "==> Terminating program!!!\n";
        cout << string(47,'*') << endl;
        return 1;
    }
    
//Tests to see if the end of the file has been reached.
    getline(InFile,line1, '\n');     // reading in the first line
    if (InFile.eof())
    {
        cout << string(16,'*') << " File is empty  " << string(16,'*') << endl;
        cout << "==> Input file is empty.\n";
        cout << "==> No information to process.\n";
        cout << "==> Terminating Program.\n";
        cout <<(47,'*') << endl << endl;
        return 1;
    }

// ***************** Part 1 **************** //

	// len_line1 = line1.length();  	 // gets the length of line 1

    // use substr and 2 operators to find the first part of the line
	// starting at 0 and going to the special character which is found from the extraction
	// of the line 2.
	
   // special_char1 = InFile.get(); 		// finds the special character from line 2
	InFile >> special_char1;

    line1_p1 = line1.substr(0, line1.find(special_char1)); 	// reads the line up until one of those characters
	
    
    line1_p2 = line1.substr(line1.find(special_char1) + 1); // reads the line after those characters
    len_line1 = line1.length();
    len_p1 = line1_p1.length();   // length of the first part of the line
    cout << len_p1;
    cout << len_line1;
    percent = (len_p1 / len_line1) * 100.0; // % of the line 1 character count
	// ************ Output data ************** //
    
    cout << "\n" << endl;
    
	cout << string(20,'*') << " First Line Information " << string(20,'*') << endl;
    cout <<"Line read: " << line1 << "[" << line1.length() << "]" << endl;
    cout << "Part 1: " << line1_p1 << "[" << line1_p1.length() << "]" << endl;
    cout << "Part 2: " << line1_p2 << "[" << line1_p2.length() << "]" << endl;
    cout << percent << " % of the characters are in the first part of the line" << endl;
    cout << string(64,'*') << endl; // end line for first line
    
    cout << "\n" << endl;

   // getline(InFile,line2,'\n');
    //cout << line2 << endl;
    //cout
    
// ******************** Part 2 ********************* //
    
    
    
    InFile.ignore(INT_MAX,'\n');
    getline(InFile,line3,'\n');
    //  getline(InFile,line4,'\n');
    InFile >> special_char2;
    //special_char2 = InFile.get();
    line2_p1 = line3.substr(0, line3.find(special_char2));   // first character in line to special character
    line2_p2 = line3.substr(line3.find(special_char2), line3.find(special_char2));   // first special char to 2nd special char
    line2_p3 = line3.substr(line3.find(special_char2) + 1); // 2nd special char to end of line
    
    // ********** Output Data ********** //
    cout << string(10,'*') << " Second Line Information " << string(10,'*') << endl;
    cout << line2_p1 << endl; // output for the different lines
    cout << line2_p2 << endl;
    cout << line2_p3 << endl;
    cout << string(45,'*') << endl;
    
    
    
    
    return 0;
    
}
