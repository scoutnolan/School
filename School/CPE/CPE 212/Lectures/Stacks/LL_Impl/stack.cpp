//*******  stack.cpp Standard Header Information Here **********
#include <cstddef>
#include <new>
#include "stack.h"
using namespace std;
//**************************************************************

Stack::Stack()			// Default constructor
{  				// Postcondition: Empty stack created
  topPtr = NULL;
}

//**************************************************************

bool Stack::IsEmpty() const		// Checks to see if stack is empty
{				// Postcondition: Returns TRUE if empty, FALSE otherwise
  return (topPtr == NULL);
}

//**************************************************************

bool Stack::IsFull() const		// Returns true if there is no room for another ItemType 
{ 				//  on the free store; false otherwise.
  NodeType* location;
  try
  {
    location = new NodeType;		// new raises an exception if no memory is available 
    delete location;
    return false;
  }
  catch(std::bad_alloc)		// This catch block processes the bad_alloc exception 
  {				// should it occur 
    return true;
  }
}

//*******  stack.cpp continued above **********

void Stack::Push(ItemType item)	// Adds item to top of stack
{				// Precondition: stack is not full 
  NodeType* tempPtr = new NodeType;
  tempPtr->info = item;
  tempPtr->next = topPtr;
  topPtr = tempPtr;
}

//**************************************************************

void Stack::Pop()			// Removes top item from stack
{				// Precondition: stack is not empty 
  NodeType* tempPtr; // new temp pointer
  tempPtr = topPtr; // set the temp pointer equal to the top pointer
  topPtr = topPtr->next; // set the top pointer equal to the next item
  delete tempPtr; // delete the temp pointer
}

//**************************************************************

ItemType Stack::Top() const		// Returns a copy of top item on stack
{				// Precondition: stack is not empty
  return topPtr->info;		// Postcondition: item still on stack, copy returned
}


//**************************************************************

void Stack::MakeEmpty()		// Returns stack to empty state 
{
  NodeType* tempPtr;

  while ( topPtr != NULL )
  {
    tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
  }
  topPtr = NULL;
}

//**************************************************************

Stack::~Stack()			// Destructor deallocates any nodes on the stack
{				// ==> Must be done to prevent memory leaks <==
  NodeType* tempPtr;

  while ( topPtr != NULL )		// Loops to deallocate all nodes
  {
    tempPtr = topPtr;
    topPtr = topPtr->next;
    delete tempPtr;
  }
}

//**************************************************************


// Linked list implementation of a stack


Stack::Stack(){
  topPtr == NULL;
}

bool Stack::IsEmpty(){
  return(topPtr == NULL);
}


bool Stack::IsFull(){

}


void Stack::Push(ItemType item){
  NodeType* temp;
  temp->info = item;
  temp->next = topPtr;
  topPtr = temp;
}


void Stack::Pop(){
  NodeType* node;
  node = topPtr;
  topPtr = topPtr->next;
  delete node;
}


ItemType Stack::Top(){
  return topPtr->info;
}


void Stack::MakeEmpty(){
  NodeType* temp;
  while(topPtr!=NULL){
    temp = topPtr;
    topPtr = topPtr->next;
    delete temp;
  }
  topPtr = NULL;
}


Stack::~Stack(){
  NodeType* temp;
  while(topPtr!= NULL){
    temp = topPtr;
    topPtr = topPtr->next;
    delete temp;
  }
}















Stack::Stack(){
  topPtr = NULL;
}


bool Stack::IsEmpty(){
  return(topPtr == NULL);
}



void Stack::Push(ItemType item){
  NodeType* temp;
  temp->info = item;
  temp->next = topPtr;
  topPtr = temp;
}

void Stack::Pop(){
  NodeType* temp;
  temp = topPtr;
  topPtr = topPtr->info;
  delete temp;
}





void Stack::MakeEmpty(){
  NodeType* temp;
  while(topPtr != NULL)
  {
    temp = topPtr;
    topPtr = topPtr->info;
    delete temp;
  }
  topPtr = NULL;
}