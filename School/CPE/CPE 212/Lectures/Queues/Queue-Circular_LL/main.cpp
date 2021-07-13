#include <iostream>
#include <fstream>

#include "queue.h"

using namespace std;

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  int item;
  QueType queue;
  int numCommands;


  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;

  inFile >> command;	 // Priming read

// Test driver continued
  numCommands = 0;
  while (command != "Quit")
  { 
    try 
    {
      if (command == "Enqueue")
      {
        inFile >> item; 
        queue.Enqueue(item);
        outFile << item << " is enqueued." << endl;
      }
      else if (command == "Dequeue")
      {
        queue.Dequeue(item); 
        outFile<< item  << " is dequeued. " << endl;
      } 
      else if (command == "IsEmpty") 
        if (queue.IsEmpty())
        {
            outFile << "Queue is empty." << endl;
        }
        else 
        {
            outFile << "Queue is not empty." << endl;
        }    
      else if (command == "IsFull")
      {
        if (queue.IsFull()) {
            outFile << "Queue is full." << endl;
        }
        else
        {
            outFile << "Queue is not full."  << endl;  
        }
      }
        
    }
    catch (FullQueue) 	// FullQueue exception handler
    {
      outFile << "FullQueue exception thrown." << endl;
    }
    
    catch (EmptyQueue)	// EmptyQueue exception handler
    {
      outFile << "EmtpyQueue exception thrown." << endl;
    }    
    numCommands++;
    cout <<  " Command number " << numCommands << " completed." 
         << endl;
    inFile >> command;
 
  };

  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();
  return 0;
} // End main() 

  
