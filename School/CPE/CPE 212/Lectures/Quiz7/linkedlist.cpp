#include <string>

#include <iostream>

#include <cstddef>
using namespace std;
typedef int ItemType;       // Data type of each item in list

struct NodeType {

    ItemType value;

    NodeType* nextNode;

};

class LList {

private:

    NodeType* head;         // Head of linked list

public:

    LList() {
        head = NULL;
        // Implement the constructor

    };

    bool IsEmpty() const {
        return (head == NULL);
        // Return if it is empty

    };

    void Print() const {
        cout << "Printing the list" << endl;
        NodeType* currentNodePtr = head;

        while (currentNodePtr != NULL) 
        {
            cout << currentNodePtr->value << endl;
            currentNodePtr = currentNodePtr->nextNode;
        }
        // Print the contents of the list
    };

    void Insert(ItemType item) {
    NodeType* currentItem = head;
    NodeType* previousItem = NULL;
    bool moreToSearch = (IsEmpty());
    while(moreToSearch)
    {
        if(&currentItem == item)
        {
            moreToSearch = false;
        }
        if(&currentItem < item)
        {
            previousItem = currentItem;
            currentItem = currentItem->nextNode;
            moreToSearch = (currentItem != NULL);
        }
        if(&currentItem > item)
        {
            moreToSearch = false;
        }
        NodeType* tempNode;
        tempNode->nextNode = currentItem;
        previousItem->nextNode = currentItem;
    }


    // NodeType* newNode;
    // NodeType* predLoc;
    // NodeType* location;
    // bool moreToSearch;
    // location = nextNode;
    // predLoc = NULL;
    // moreToSearch = (location != NULL);
    // while(moreToSearch)
    // {
    //     switch(item.ComparedTo(location->head))
    //     {
    //         case GREATER:   predLoc = location;
    //                         location = location->nextNode;
    //                         moreToSearch = (location != NULL);
    //                         break;
    //         case LESS:      moreToSearch = false;
    //                         break;    
    //     }
    //     newNode = new NodeType;
    //     newNode->head = item;

    //     if(predLoc == NULL)
    //     {
    //         newNode->head = nextNode;
    //         nextNode = newNode;
    //     }
    //     else
    //     {
    //         newNode->head = location;
    //         predLoc->head = newNode;
    //     }
    // }
        // You will need to insert in ascending order
        // i.e 1,2,3...etc
        // I tried implementing the function you showed us on monday in the slides..
    };

    ~LList() {
        ItemType someItem;
        while ( !IsEmpty() ) 
        {
            NodeType* tempPtr = head;
            someItem = head->value;
            head = head->nextNode;
            delete tempPtr;
        }
        // Implement the destructor

    };

};

int main() {

    LList list;

    list.Insert(35);

    list.Insert(10);

    list.Insert(20);

    list.Insert(5);

    list.Insert(60);

    list.Insert(25);

    list.Print();

    return 0;

}

