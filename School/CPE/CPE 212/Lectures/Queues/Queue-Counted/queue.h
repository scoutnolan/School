// Header: CountedQueType.h

typedef char ItemType;

#include "queueType.h"

class CountedQueType : public QueType
{
  private:
    int length;

  public:
    CountedQueType(int max);		
    void Enqueue(ItemType newItem);	
    void Dequeue(ItemType& item);
    int LengthIs() const;	
    // Returns the number of items on the queue.
};
