#ifndef LINKED_LIST_LLIST_H
#define LINKED_LIST_LLIST_H

struct NodeType;			// Forward declaration, complete declaration in LList.cpp

typedef int ItemType;		// Data type of each item in list

class LList {
private:
    NodeType* head;			// Head of linked list

public:
    /**
     * Default constructor
     * @post Empty list created
     */
    LList();

    /**
     * Method to check to see if the list is empty
     * @post Returns TRUE if empty else FALSE
     */
    bool IsEmpty() const;


    /**
     * Method to print the contents of the list
     * @post The list contents, if any, are printed to the console
     */
    void Print() const;

    /**
     * Method to add an item to the beginning of the list
     * @param item ItemType
     * @pre Item is less than the first item in the list
     * @post Item is first in the list and the list items are in order
     */
    void InsertAsFirst(ItemType item);


    /**
     * Method to insert an item in the correct place in the list
     * @param item ItemType
     * @pre The items in the list are in ascending order
     * @post The new node containing the item is added to the sorted list
     */
    void Insert(ItemType item);


    /**
     * Method to remove the first item in the list
     * @param item ItemType&
     * @post The first item in the list is removed and the head is now pointing to the next node
     */
    void RemoveFirst(ItemType& item);

    /**
     * Method to delete an item from the list
     * @param item ItemType
     * @pre Item is in the list
     * @post The first occurrence of th item is no longer in the list and the list remains sorted
     */
    void Delete(ItemType item);

    /**
     * Destructor
     * @post List is destroyed
     */
    ~LList();
};


#endif //LINKED_LIST_LLIST_H
