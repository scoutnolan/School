#include "templateobj.hpp"


template<typename Type>
List<Type>::List()
{
    _head = NULL;
    _tail = NULL;
}


template<typename Type>
List<Type>::~List()
{
    Node<Type> *tmp;

    while(_head != NULL)
    {
        tmp = _head;
        _head = _head->next;
        delete tmp;
    }
}

template<typename Type>
void List<Type>::Insert(const Type & data)
{
    Node<Type> *tempPtr = new Node<Type>(data);
    tempPtr->next = _head;
    _head = tempPtr;
}

template<typename Type>
void List<Type>::Print()
{
    Node<Type> *tmp = _head;
    while(tmp != NULL)
    {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }

}

template<typename Type>
Type List<Type>::front() const
{
    return _head->data;
}

template<typename Type>
Type List<Type>::back() const
{
    return _tail->data;
}

//template class List<int>;
//template class Node<int>;

