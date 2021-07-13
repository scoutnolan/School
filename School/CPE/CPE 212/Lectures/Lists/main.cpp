//*******  SomeClient.cpp continued from previous slide **********
#include <iostream>
#include <fstream>
#include "List.h"
using namespace std;

int main()
{
 List  temps;       // List of temperature values
 ifstream  dataFile;    // Input file stream
 int someTemp;      // One data value

 dataFile.open("tempsdata.txt");

 if (!dataFile)
 {
   cout << "Unable to open data file tempsdata.txt" << endl;
   return 1;
 }

 dataFile >> someTemp;  // Priming read
 while ( dataFile && !temps.IsFull() ) // While not EOF or FULL list
 {
      cout << endl << "Is the input " << someTemp << " already in the list? " << temps.IsPresent(someTemp) << endl;
        temps.Insert(someTemp);
        dataFile >> someTemp;    // Try to read another temp value from file
 }
 cout << endl << "A total of " << temps.Length() << " temperatures were input." << endl;
  // Do something useful with your list of temps here…

  

 return 0;
} // End main()
