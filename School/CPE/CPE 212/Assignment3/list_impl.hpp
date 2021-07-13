/// IMPLEMENT THE FOLLOWING FUNCTIONS
///home/facstaff/taf0004/CPE212SP20/Project03/Solution/P3 inputfilename
template<typename Type>
List<Type>::List()
{
    _firstNode = NULL;
    _lastNode = NULL;
    _count = 0;
    _iteratorNode = NULL;
    /// initialize the nodes correctly
}

template<typename Type>
List<Type>::~List()
{
    Node<Type> * tempPtr;                           // new pointer variable
    while (_iteratorNode != NULL)
    {
        tempPtr = _iteratorNode;                    // temp pointer to the iterator node
        _iteratorNode = _iteratorNode->nextItem;    // iterator node is equal to the next item
        delete tempPtr;                             // delete the tmep pointer
    }
    /// delete all data within the list, be sure to account for memory leaks.
}

template<typename Type>
void List<Type>::AppendItem(const Type &data)
{
    Node<Type>* tempPtr = new Node<Type>(data);     // new temp pointer based on the data
    if(_firstNode == NULL)                          // if the list is empty
    {
        tempPtr->localData = data;                  // accessing the local data through the temp pointer and setting it equal to the data called in
        tempPtr->nextItem = _firstNode;             // next item is equal to the first node
        _firstNode = tempPtr;                       // setting the first node to the temp pointer
        _lastNode = tempPtr;                        // one element, first is equal to last.
    }
    else                                            // i.e. if the list is not empty
    {
        tempPtr->localData = data;                  // " "
        _lastNode->nextItem = tempPtr;
        _lastNode = tempPtr;                        // set the last node equal to the temp pointer variable
    }
    _count = _count + 1;                     // increment count
}

template<typename Type>
bool List<Type>::DeleteItem(const Type &data)
{
    ResetIterator();
    if(_iteratorNode->localData != data)
    {
        while((_iteratorNode->nextItem)->localData != data && (_iteratorNode->nextItem)->nextItem != NULL) {
            _iteratorNode = _iteratorNode->nextItem;
        }
        if ((_iteratorNode->nextItem)->localData == data)
        {
            Node<Type>* tempNode;
            tempNode = _iteratorNode->nextItem;
            _iteratorNode->nextItem = (_iteratorNode->nextItem)->nextItem;
            delete tempNode;
            _count--;
            return true;
        }else{
            return false;
        }
        
        }else{
            Node<Type>* tempNode = _firstNode;
            _firstNode = _firstNode->nextItem;
            delete tempNode;
            _count--;
            return true;
        }
}
    /// remove an item correctly to the list
    /// All items in this project will be equal comparable
    /// return false if the item was not removed
    /// return true if the item was removed.
    /// decrement _count if the item was removed
template<typename Type>
unsigned int List<Type>::Count() const
{
    /// returns the size from _count.
    return _count;
}

template<typename Type>
Type& List<Type>::Front()
{
    return _firstNode->localData;
    /// returns a reference to the data in the front of the list
}

template<typename Type>
Type List<Type>::Front() const
{
    return *_firstNode->localData;
    /// returns a const copy to the data in the front of the list.
}

template<typename Type>
Type& List<Type>::Back()
{
    return _lastNode->localData;
    /// returns a reference to the data in the back of the list.
}

template<typename Type>
Type List<Type>::Back() const
{
    return *_lastNode->localData;
    /// returns a const copy to the data in the back of the list
}

template<typename Type>
Type* List<Type>::IterateItems() const
{

    Type *tempPtr;                              // new temp variable
    tempPtr = &(_iteratorNode->localData);      // temp pointer to the reference of the iteratornode pointing to the local data
    _iteratorNode = _iteratorNode->nextItem;    // iterator node to the next item
    return tempPtr;                             // return the temp pointer

}

template<typename Type>
bool List<Type>::AtEnd() const
{
    if (_iteratorNode == NULL) // if the iterator node is empty
    {
        return true;           // return true
    }
    else                       // if the iterator node is not empty
    {
        return false;          // return false
    }
    /// returns if your iterator pointer is at the end of the list
}

template<typename Type>
void List<Type>::ResetIterator() const
{
    _iteratorNode = _firstNode;
    /// resets your iterator pointer to the beginning.
}