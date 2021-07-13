#ifndef TEMP_HPP
#define TEMP_HPP

#include <new>
#include <iostream>

template<typename Type>
struct Node
{
    Type data;
    Node<Type> *next;

    Node(const Type & t)
    {
        data = t;
        next = NULL;
    }
};

template<typename Type>
class List
{
private:
    Node<Type> *_head;
    Node<Type> *_tail;

public:
    List();
    ~List();

    void Insert(const Type& data);
    void Print();

    Type front() const;
    Type back() const;
};


#endif
