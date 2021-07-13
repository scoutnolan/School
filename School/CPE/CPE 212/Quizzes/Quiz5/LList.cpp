#include <cstddef>
#include <iostream>
#include "LList.h"

using namespace std;

struct NodeType {
    ItemType value;
    NodeType* nextNode;
};

LList::LList() {
    head = NULL;
}

LList::~LList() {
    ItemType someItem;

    while ( !IsEmpty() ) {
        RemoveFirst(someItem);
    }
}

bool LList::IsEmpty() const {
    return (head == NULL);
}

/**
 * TODO: Implement the print method for the linked list
 */

void LList::Print() const{
    cout << "Printng the list" << endl;
    NodeType* currentNodePtr = head;
    while(currentNodePtr != NULL){
        cout << currentNodePtr->value << endl;
        currentNodePtr = currentNodePtr->nextNode;
    }
}

/**
 * TODO: Implement the print method for the linked list
 */

void LList::InsertAsFirst(ItemType item) {
    NodeType* tempPtr = new NodeType;

    tempPtr->value = item;
    tempPtr->nextNode = head;
    head = tempPtr;
}

void LList::RemoveFirst(ItemType &item) {
    NodeType* tempPtr = head;
    item = head->value;
    head = head->nextNode;
    delete tempPtr;
}

void LList::Delete(ItemType item) {
    // How would we get this done? 
    
}




