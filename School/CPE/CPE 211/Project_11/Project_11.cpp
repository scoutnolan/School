// ****************************
// Project Title: Project 11
// Project File: Project_11.cpp
// Name: Nolan Anderson
// Course Section CPE-211-01
// Lab Section: 2
// Due Date: 9/04/2019
// program description: takes in input from a file and counts amount of a specific type of character
// What the program does
// ****************************
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <string>
using namespace std;

// /home/work/cpe211/Executables/Project_11/Project_11_solution
// /home/work/cpe211data/Project_11/CompareSolution.bash  Project_11.cpp

// ********** Function Declaration ********** //

void OpenInputFile(ifstream&);
bool ReadInfo(ifstream&);

// ********** Main ********** //

int main()
{
    ifstream inFile;
    string line;
    OpenInputFile(inFile);
    ReadInfo(inFile);
	return 0;
}

// ********** Open Input File ********** //

void OpenInputFile(ifstream& input)
{
    string inFile;
    cout << endl;
    cout << "Enter in the name of the input file: ";
    cin >> inFile;
    cout << inFile;
    input.open(inFile.c_str());
    while (input.fail()) // if the file does not open then ask for a new input file until a good one is submitted.
    {
        input.clear();
        cout << endl << endl;
        cout << string(15,'*') << " File Open Error " << string(15,'*') << endl;
        cout << "==> Input file failed to open properly!!" << endl;
        cout << "==> Attempted to open file: " << inFile << endl;
        cout << "==> Please try again..." << endl;
        cout << "***********************************************" << endl;
        cout << endl;
        cout << "Enter in the name of the input file: ";
        cin >> inFile;
        cout << inFile;
        input.open(inFile.c_str());
    }
}

// ********** Reading in Info ********** //

bool ReadInfo(ifstream& input)
{
    char ch;
    string line1;
    input.get(ch);
    if (input.eof() == true)
    {
        cout << endl;
        cout << endl << string(13,'*') << " Input File Is Empty " << string(13,'*') << endl;
        cout << "==> The input file is empty." << endl;
        cout << "==> Terminating the program." << endl;
        cout << "***********************************************" << endl << endl;
        return false;
    }
    
// ********** Declaring variables loops ********** //
    
    int upper_c = 0, lower_c = 0, digits_c = 0, punct_c = 0, spaces_c = 0, other_c = 0, line_c = 0;
    int up_tot = 0, low_tot = 0, dig_tot = 0, pun_tot = 0, spac_tot = 0, o_tot = 0, line_tot = 0, total = 0;
    float up_p = 0, low_p = 0, dig_p = 0,  pun_p = 0, spac_p = 0, o_p = 0;
    
// ********** Initial line output ********** //
    
    cout << endl << endl;
    cout << "Line number    Upper     Lower     Digits    Punct     Spaces    Other     Total" << endl;
    cout << "-----------    -----     -----     ------    -----     ------    -----     -----" << endl;
    
// ********** Loops to count characters in lines ********** //
    
    line_c = 1;
    do
    {
        //cout << "Character: " << ch << endl << endl;
        if (isupper(ch)) // if it is an upper case
        {
            upper_c++;
            up_tot++;
            line_tot++;
            total++;
        }
        else if(islower(ch)) // if it is lower case
        {
            lower_c++;
            low_tot++;
            line_tot++;
            total++;
        }
        else if(isdigit(ch)) // if it is a digit
        {
            digits_c++;
            dig_tot++;
            line_tot++;
            total++;
        }
        else if(ispunct(ch)) // if it is a punctuation
        {
            punct_c++;
            pun_tot++;
            line_tot++;
            total++;
        }
        else if(isprint(ch) || ch == '\t') // if it is a space
        {
            spaces_c++;
            spac_tot++;
            line_tot++;
            total++;
        }
        else                  // all other characters
        {
            other_c++;
            o_tot++;
            line_tot++;
            total++;
        }
        
        // ********** Output For Numbers Found ********** //
        
        
        if (ch == '\n')
        {
            cout << setw(15) << left << line_c      // line number
            << setw(10) << left << upper_c     // upper letters
            << setw(10) << left << lower_c     // lower letters
            << setw(10) << left << digits_c    // digits
            << setw(10) << left << punct_c     // punctuation
            << setw(10) << left << spaces_c    // spaces
            << setw(10) << left << other_c     // other characters
            << left << line_tot << endl;
            
            upper_c = lower_c = digits_c = punct_c = spaces_c = other_c = line_tot = 0; // resetting the values back to
            //zero for the next line of characters
            line_c++;
        }

    }while(input.get(ch));
    
// ********** Totals ********** //
    
    //cout << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << setw(15) << left << "Totals" << setw(10) << left << up_tot     // total upper case
    << setw(10) << left << low_tot                      // total lowercase
    << setw(10) << left << dig_tot                      // total digit
    << setw(10) << left << pun_tot                      // total punctuation
    << setw(10) << left << spac_tot                     // space total
    << setw(10) << left << o_tot
    << left << total << endl;
    
// ********** Percentage Calculation ********** //
    
    up_p = 100*((float)up_tot / (float)total);     // percentage of upper
    low_p = 100*((float)low_tot / (float)total);   // percentage of lower
    dig_p = 100*((float)dig_tot / (float)total);   // percentage of digits
    pun_p = 100*((float)pun_tot / (float)total);   // percentage of punctuation
    spac_p = 100*((float)spac_tot / (float)total); // percentage of spaces
    o_p = 100*((float)o_tot / (float)total);       // percentage of other
    
// ********** Percentage Output ********* //
    
    cout << setw(15) << left << "Percent" << setw(10) << fixed << setprecision(2) << left << up_p
    << setw(10) << left << low_p
    << setw(10) << left << dig_p
    << setw(10) << left << pun_p
    << setw(10) << left << spac_p
    << setw(10) << left << o_p << endl << endl;
}
