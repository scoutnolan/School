// Header file for Queue LL
#include <new>

class FullQueue
{};  

class EmptyQueue
{};  
 
typedef int ItemType;

struct NodeType
{
  ItemType info;
  NodeType* next;
};


class QueType
{
  private:
    NodeType* front;
    NodeType* rear;

  public: 
    QueType(); 		// Class constructor.
    
    ~QueType();		// Class destructor.
    
    void MakeEmpty();		// Function: Initializes the queue to an empty state.

    bool IsEmpty() const;	// Function: Determines whether the queue is empty.
    
    bool IsFull() const;	// Function: Determines whether the queue is full.
    
    void Enqueue(ItemType newItem);	// Function: Adds newItem to the rear of the queue.

    void Dequeue(ItemType& item);	 // Function: Removes front item from the queue and returns it in item.
};

