template<typename Type>
List<Type>::List()
{
    /**
     * Insert the content for the constructor
     */
     _firstNode = NULL;
    _lastNode = NULL;
    _count = 0;
    _iteratorNode = NULL;
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
    /**
     * Insert the content for the destructor
     */
}

template<typename Type>
void List<Type>::AddItemSorted(const Type &data)
{
    ResetIterator();
    Node<Type> *newNode = new Node<Type>(data); //pointer to node being inserted
    Node<Type> *current = _firstNode;
    Node<Type> *previous = NULL;
    bool moreToSearch;
    moreToSearch = (current != NULL);
    while(moreToSearch)
    {
        if(current->localData <= data)
        {
            previous = current;
            current = current->nextItem;
            moreToSearch = (current!=NULL);
        }
        else
        {
            moreToSearch = false;
        }
    }
    if(previous == NULL)
    {
        newNode->nextItem = _firstNode;
        _firstNode = newNode;
    }
    else
    {
        newNode->nextItem = current;
        previous->nextItem = newNode;
    }
    _count++;
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
    /**
     * Deletes a provided item from the list
     */
}

template<typename Type>
unsigned int List<Type>::Count() const
{
    return _count;
    /**
     * Returns the number of items in the list
     */
}

template<typename Type>
Type& List<Type>::Front()
{
    return _firstNode->localData;
    /**
     * Returns the reference to the item at the front of the list
     */
}

template<typename Type>
Type List<Type>::Front() const
{
    return *_firstNode->localData;
    /**
     * Returns a const copy to the data that is at the front of the list
     */
}

template<typename Type>
Type& List<Type>::Back()
{
    return _lastNode->localData;
    /**
     * Returns a reference to the item at the back of the list
     */
}

template<typename Type>
Type List<Type>::Back() const
{
    return *_lastNode->localData;
    /**
     * Returns a const copy to the item at the back of the list
     */
}

template<typename Type>
Type* List<Type>::IterateItems() const
{
    Type *tempPtr;                              // new temp variable
    tempPtr = &(_iteratorNode->localData);      // temp pointer to the reference of the iteratornode pointing to the local data
    _iteratorNode = _iteratorNode->nextItem;    // iterator node to the next item
    return tempPtr;                             // return the temp pointer
    /**
     * Provides a pointer to the current item at the _iterator pointer.
     * It moves the iterator pointer to the next item in the list.
     */
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
    /**
     * Returns if the iterator pointer is at the end of the list
     */
}

template<typename Type>
void List<Type>::ResetIterator() const
{
    _iteratorNode = _firstNode;
    /**
     * Resets the iterator pointer to the beginning of the list
     */
}

template<typename Type>
Type List<Type>::PopFront()
{
    Node<Type>* tempPtr = _firstNode; // new temp pointer
    //tempPtr = _firstNode; // set the temp pointer equal to the first pointer
    _firstNode = _firstNode->nextItem; // set the front pointer equal to the next item
    return tempPtr->localData; // delete the temp pointer, which is the "old" _frontNode

    /**
     * Method that will Pop the first item off of the front of the list.
     * This will remove the item from the list and return its value to the caller.
     */
}