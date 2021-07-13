#include <iostream>
#include <fstream>
using namespace std;
typedef int ItemType;
struct Node
{
    ItemType info;
    Node* next;
};
    
class Stack
{
    private:
    Node* lastNode;
    public:
    Stack();
    void push(ItemType item);
    void pop();
};

int main() 

{ 

     Stack s; 

    s.push(10); 

    s.push(20); 

    s.push(30); 

    cout << s.pop() << " Popped from stack\n"; 

  

    return 0; 

}

Stack::Stack(){
    lastNode = NULL;
}

void Stack::push(ItemType item){
    ItemType* temp = new ItemType; // temporary variable
    temp->info = item;
    temp->next = lastNode; // 
    lastNode = temp; // last node is equal to temp
}

void Stack::pop(){
    ItemType* temp;          // creating a temp variable
    temp = lastNode;    // setting the temp equal to the last node
    lastNode = lastNode->next; // last node is equal to the info there
    delete temp; // delete the temp pointer
}