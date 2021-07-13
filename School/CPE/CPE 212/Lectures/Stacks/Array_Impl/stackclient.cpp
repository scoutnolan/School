//*******  stackclient.cpp Standard Header Information Here **********
#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

int main()
{
  Stack temps;
  ifstream datafile;
  ItemType someTemp;

  datafile.open("June05Temps.txt");

  datafile >> someTemp;
  while (datafile)
  {
    if ( !temps.IsFull() )
    {
      temps.Push(someTemp);
    }
    datafile >> someTemp;
  }
  
  while ( !temps.IsEmpty() )
  {
    cout << temps.Top() << endl;
    temps.Pop();
  }

  return 0;
}
