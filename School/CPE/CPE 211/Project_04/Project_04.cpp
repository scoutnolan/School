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
#include <cstring>
using namespace std;

int main()
{
    
	// Input of the file
	
	string filename;
	ifstream InFile;
	cout << "Enter name of the input file: " << endl;
    cin >> filename;
    InFile.open(filename.c_str());
    
    
    
    
    // Delcaring part 1
    char special_char1;
    string line4, line1, line1_p1, line1_p2, line3;
    float len_p1, len_p2, len_line1, percent;
    
    // Declaring part 2
    char special_char2;
    string line2, line2_p1, line2_p2, line2_p3;
    int setw_length_1a, setw_length_2a, setw_length_3a, setw_length_1, setw_length_2, setw_length_3;

    
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
    getline(InFile,line1, '\n');    						// reading in the first line
    if (InFile.eof())
    {
        cout << string(16,'*') << " File is empty  " << string(16,'*') << endl;
        cout << "==> Input file is empty.\n";
        cout << "==> No information to process.\n";
        cout << "==> Terminating Program.\n";
        cout <<(47,'*') << endl << endl;
        return 1;
    }




// ********************************** Part 1 ********************************* //
	
	
	// ************** Getting Data *************** // 
	


	InFile >> special_char1;								// Finds the special character
	line1_p1 = line1.substr(0, line1.find(special_char1)); 	// reads the line up until one of those characters
	line1_p2 = line1.substr(line1.find(special_char1) + 1); // reads the line after those characters
    len_line1 = line1.length();								// length of line 1
    len_p1 = line1_p1.length();   							// length of the first part of the line
    len_p2 = line1_p2.length();								// length of the second part of the line
    percent = (len_p1 / len_line1) * 100.0; 				// % of the line 1 character count
    
	// ************ Output data ************** //
    
    cout << "\n" << endl;

	cout << string(20,'*') << " First Line Information " << string(20,'*') << endl;
    cout << right << setw(15) << "Line read: " << line1 << "[" << line1.length() << "]" << endl;
 	cout << right << setw(15) << "Part 1: " << line1_p1 << "[" << line1_p1.length() << "]" << endl;
    cout << right << setw(15) << "Part 2: " << line1_p2 << "[" << line1_p2.length() << "]" << endl;
    cout << showpoint << setprecision(4) << percent << " % of the characters are in the first part of the line" << endl;
    cout << string(64,'*') << endl; // end line for first line
    
    cout << "\n" << endl;
    
// ********************************** Part 2 ********************************* //
    
    
    // *********** Getting Data *************** // 
    
	InFile.ignore(INT_MAX,'\n');							 // ignores the previous line
    getline(InFile,line3,'\n');								 // Gets the new line
    InFile >> special_char2;								 // operation to get the special character
    
    line2_p1 = line3.substr(0, line3.find(special_char2));   // first character in line to special character
	line2_p2 = line3.substr(line3.find(special_char2), line3.find(special_char2));   // first special char to 2nd special char
    line2_p3 = line3.substr(line3.find(special_char2) + 1); // 2nd special char to end of line
    setw_length_1 = (line2_p1.length() + 45) / 2;			 // setw operation to find middle
    setw_length_2 = (line2_p2.length() + 45) / 2;
    setw_length_3 = (line2_p3.length() + 45) / 2;
    
    // ********** Output Data ********** //
    cout << string(10,'*') << " Second Line Information " << string(10,'*') << endl;
    cout << right << setw(setw_length_1) << line2_p1 << endl; // right justified with setw in the middle of the output.
    cout << right << setw(setw_length_2) << line2_p2 << endl;
    cout << right << setw(setw_length_3) << line2_p3 << endl;
    cout << string(45,'*') << endl;
    
    
    
    
    return 0;
    
}
