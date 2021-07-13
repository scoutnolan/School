//*******  stack.h Standard Header Information Here **********
#ifndef STACK_H
#define STACK_H
typedef int ItemType;		// Data type of each item on stack

struct NodeType			// Declaration of the node stucture
{
  ItemType info;			// Field storing the data
  NodeType* next;			// Field storing address of next node in sequence
};

class Stack			// Linked Node-based Stack class
{
 private:
  NodeType* topPtr;			// Top of stack pointer

 public:
  Stack();			// Default constructor creates an empty stack 

  bool IsEmpty() const;		// Returns TRUE if empty, FALSE otherwise

  bool IsFull() const;		// Returns TRUE if full, FALSE otherwise

  void Push(ItemType item);		// Adds item to top of stack

  void Pop();			// Removes top item from stack

  ItemType Top() const;		// Returns copy of top item on stack assuming it exists

  void MakeEmpty();			// Returns stack to empty state

  ~Stack();			// Destructor deallocates any nodes 
};				

#endif

