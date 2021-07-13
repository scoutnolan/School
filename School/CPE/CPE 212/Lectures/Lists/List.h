#ifndef LIST_CLASS_H_

 #define LIST_CLASS_H_
  
 const int MAX_LENGTH = 100;       // Maximum number of list items
  
 typedef int ItemType;     // Data type of each item in list

 class List            // Unordered list of items
 {
   private:
      int  length;         // Actual number of items in list
      ItemType  data[MAX_LENGTH];  // List of unsorted data items

   public:
      List();          // Default constructor creates empty list
      bool IsEmpty() const;        // Returns TRUE if empty, FALSE otherwise
      bool IsFull() const;     // Returns TRUE if full, FALSE otherwise
      int  Length() const;     // Returns length of list
      void Insert(ItemType item);  // Adds item to end of list assuming list is not full
      void Delete(ItemType item);  // Removes first item occurrence from list if not empty
      bool IsPresent(ItemType item);   // Returns TRUE if item in list, otherwise FALSE
 };

#endif  // End of LIST_CLASS_H_

