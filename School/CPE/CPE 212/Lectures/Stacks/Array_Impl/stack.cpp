//*******  stack.cpp Standard Header Information Here **********
#include "stack.h"

Stack::Stack()			// Default constructor
{  				// Postcondition: Empty stack created
  top = -1;
}

bool Stack::IsEmpty() const		// Checks to see if stack is empty
{				// Postcondition: Returns TRUE if empty, FALSE otherwise
  return (top == -1);
}

bool Stack::IsFull() const		// Checks to see if stack is full
{				// Postcondition: Returns TRUE if full, FALSE otherwise
  return (top == (MAX_SIZE-1));
}

void Stack::Push(ItemType item)		// Adds item to top of stack
{				// Precondition: stack is not full 
  top++;
  data[top] = item;
}

void Stack::Pop()			// Removes top item from stack
{				// Precondition: stack is not empty 
  top--;
}

ItemType Stack::Top() const		// Returns a copy of top item on stack
{				// Precondition: stack is not empty
  return data[top];			// Postcondition: item still on stack, copy returned
}

void Stack::MakeEmpty()			// Removes all items from stack
{
  top = -1;
}







// stack implementation using array


Stack::Stack(){
  top = -1;
}

bool Stack::IsEmpty(){
  return(top==-1);
}

bool Stack::IsFull(){
  return(top==(MAX_SIZE-1));
}

void Stack::Push(ItemType item){
  top++;
  data[top] = item;
}

void Stack::Pop(){
  top--;
}


ItemType Stack::Top(){
  return data[top];
}

void Stack::MakeEmpty(){
  top == -1;
}
