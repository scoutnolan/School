//*******  stack.h Standard Header Information Here **********

const int MAX_SIZE = 100;		// Maximum stack size 

typedef int ItemType;		// Data type of each item on stack

class Stack			// Array-based Stack class
{
 private:
  ItemType data[MAX_SIZE];		// Array of stack data
  int top;			// Top of stack indicator

 public:
  Stack();			// Default constructor
  				// Postcondition: Empty stack created

  bool IsEmpty() const;		// Checks to see if stack is empty
				// Postcondition: Returns TRUE if empty, FALSE otherwise

  bool IsFull() const;		// Checks to see if stack is full
				// Postcondition: Returns TRUE if full, FALSE otherwise

  void Push(ItemType item);		// Adds item to top of stack

  void Pop();			// Removes top item from stack

  ItemType Top() const;		// Returns a copy of top item on stack
				// Postcondition: item still on stack, copy returned

  void MakeEmpty();			// Removes all items from stack
};				
