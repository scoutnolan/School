//*******  List.cpp Standard Header Information Here **********
#include "List.h"
  
List::List()            // Default constructor creates empty list
{
 length = 0;
} // End List::List()

bool List::IsEmpty() const      // Returns TRUE if empty, FALSE otherwise
{
 return (length == 0);
} // End List::IsEmpty()

bool List::IsFull() const       // Returns TRUE if full, FALSE otherwise
{
 return (length == MAX_LENGTH);
} // End List::IsFull()

int List::Length() const        // Returns length of list
{
 return length;
} // End List::Length()

void List::Insert(ItemType item)    // Adds item to end of list assuming list is not full
{
 data[length] = item;
 length++;
} // End List::Insert(…)


void List::Delete(ItemType item)    // Removes first occurrence from list if not empty
{
 int index = 0;

 while ((index < length) && (item != data[index])) // Locate item index first
 {
   index++;
 }

 if (index < length)
 {
   data[index] = data[length-1];   // Overwrite item with last item in the list
   length--;
 }
} // End List::Delete(…)

//*******  List.cpp continued from previous slide **********


bool List::IsPresent(ItemType item)  // Returns TRUE if item in list, otherwise FALSE
{
 int index = 0;

 while ((index < length) && (item != data[index])) // Locate item index first
 {
   index++;
 }

 return (index < length);  // index == length => item not found.  Index < length => item found

} // End List::IsPresent(…)