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

void LList::Print() const {
    cout << "Printing the list" << endl;
    NodeType* currentNodePtr = head;

    while (currentNodePtr != NULL) {
        cout << currentNodePtr->value << endl;
        currentNodePtr = currentNodePtr->nextNode;
    }
}

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

void LList::Insert(ItemType item) {
    // Create a tempPtr

    // What happens when the head is null? 

    // Looking for the insertion point
        // Check to see if the value of the here

        // Check to see if the value of where you are is less than the item and make sure the next node isn't pointing to NULL
                // Point the next node of the temp to be the next node of the current node
                // Point the next node of the current node to the temp
        // If the next node is NULL you are putting the item on the end 
    // Don't forget to increment where you are
}

void LList::Delete(ItemType item) {
    // How would we get this done? 
}





/*
CurrentItem = begin;
previousItem = NULL;
moreToSearch = (Length() > 0) // true if the length is greater than 0
while(moreToSearch)           // while the length is more than 0
{
    if(currentItem == item)
    {
        return false; // if the current item is equal to the item you are looking at, then you do not add it.
    }
    if(currentItem < item) // if the current item is less than the item being called in then do this
    {
        // set the previous item equal to the current item
        // the current item will equal the currentItem pointing to the next item
        // moreToSearch will be true if the current item is not null, as in it will be true if the current item is not at the end of the list.

    }
    if(currentItem > item)
    {
        // if the current item is greater than the item, then do this
        // essentially if the current item is greater, then you need to insert the item just before the current item.
        moreToSearch = false;
    }
    // create a new node
    nodetype* tempNode;
    tempNode->next = currentItem;
    previousItem->next = currentItem;


}
*/


bool Insert(ItemType item)
{
    CurrentItem = begin; // set the current item equal to the head
    previousItem = NULL; // set the previous item equal to NULL, since before the head is null
    moreToSearch = (Length() > 0); // true if length is greater than 0, if it is not true then skip the while loop.
    while(moreToSearch)
    {
        if(currentItem = item)
        {
            return false;
        }
        if(currentItem < item)
        {
            previousItem = currentItem;
            currentItem = currentItem->next;
            moreToSearch = (currentItem != NULL);
        }
        if(currentItem > item)
        {
            moreToSearch = false;
        }
        NodeType* tempNode;
        tempNode -> next = currentItem; // set the temp node pointing to next equal to the current item
        previousItem->next = currentItem; // set the previous item equal to the current item
    }
}


bool Insert(ItemType item)
{
    currentItem = begin;
    previousItem = NULL;
    moreToSearch = (Length() > 0)
    while(moreToSearch)
    {
        if(currentItem == item)
        {
            return false;
        }
        if(currentItem < item)
        {
            previousItem = currentItem; // previous item is equal to the current item
            currentItem = currentItem -> next; // current item updated with the value pointing to next
            moreToSearch = (currentItem != NULL); // keep searching if the current item is not null;
        }
        if(currentItem > item)
        {
            moreToSearch = false
        }
        NodeType* tempNode; // create a temp pointer
        tempNode -> next = currentItem; // tempNode is equal to the current item
        previousItem->next = currentItem; // set the previous item pointing to next equal to the current item
    }
}





bool Insert(NodeType node)
{
    currentItem = begin;
    previousItem = NULL;
    moreToSearch = (Length() > 0);
    while(moreToSearch)
    {
        if(currentItem == item)
        {
            return false;
        }
        if(currentItem < item)
        {
            previousItem = currentItem;
            currentItem = currentItem->next;
            moreToSearch = (currentItem != NULL);
        }
        if(currentItem > item)
        {
            moreToSearch = false;
        }
        NodeType* tempnode;
        nodetemp->next = currentItem;
        previousItem->next = currentItem;
    }
}

