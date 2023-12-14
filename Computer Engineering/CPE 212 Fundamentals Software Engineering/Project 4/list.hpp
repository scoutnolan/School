#ifndef LIST_HPP
#define LIST_HPP

#include <new>
#include <iostream>

template<typename Type>
struct Node
{
    Type localData;
    Node<Type> *nextItem;

    Node(const Type &data)
    {
        localData = data;
        nextItem = NULL;
    }
};

/// List must be implemented by the student
template<typename Type>
class List
{
private:
    Node<Type> *_firstNode;
    Node<Type> *_lastNode;

    mutable Node<Type> *_iteratorNode;

    unsigned int _count;


public:
    List();
    ~List();

    void AddItemSorted(const Type &data);
    bool DeleteItem(const Type &data);
    unsigned int Count() const;

    Type& Front();
    Type Front() const;
    Type PopFront();
    Type& Back();
    Type Back() const;

    Type* IterateItems() const;
    bool AtEnd() const;
    void ResetIterator() const;
};

#include "list_impl.hpp"


#endif // #ifndef LIST_HPP