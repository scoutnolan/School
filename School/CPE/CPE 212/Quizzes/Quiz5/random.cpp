struct node{
    int data;
    node * next;
};



int main(){
    node * n;
    node * t; // temp pointer
    node * h; // head
    n = new node;
    n->data=1;
    t = n;
    h = n;
    
}


NodeType* tempPtr = head;
    item = head->value;
    head = head->nextNode;
    head = tempPtr;
    if(head = tempPtr){ // if the list is not empty
        head = head->nextNode;
        delete tempPtr; // delete the first value
    }
    else{
        while(tempPtr != head){
            //tempPtr = tempPtr->nextNode; // moving the tempPtr to the next node
            head = head->nextNode; // moving the head to the next node.
            if (tempPtr = head){ // if the tempPtr is equal to the head, then delete it.
                delete tempPtr;
            }
        }
    }
    cout << "Delete function ";
    Print();