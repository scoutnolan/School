//*******  stackclient.cpp Standard Header Information Here **********
#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

int main()	// Note:  Implementation changed but no change in client program!!
{
  Stack temps;
  ifstream datafile;
  ItemType someTemp;

  datafile.open("June05Temps.txt");

  cout << "Raw Data" << endl;
  datafile >> someTemp;
  while (datafile)
  {
    cout << someTemp << endl;
    if ( !temps.IsFull() )
    {
      temps.Push(someTemp);
    }
    datafile >> someTemp;
  }
  
  cout << "Stack Values" << endl;
  while ( !temps.IsEmpty() )
  {
    cout << temps.Top() << endl;
    temps.Pop();
  }

  return 0;
}
