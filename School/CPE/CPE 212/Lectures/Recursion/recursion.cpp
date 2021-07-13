#include <string>
#include <iostream>
using namespace std;

void foo(int);
void bar(int);
int factorial(int);
void printn(int);


int main()
{
    int i = 5;
    int fact = 20;
    foo(i);
    factorial(fact);
    int num;
    cout << "Please enter a number ";
    cin >> num; 
    cout << endl;
    printn(num);
}


void foo(int j)
{
    cout << j << endl;
    int k = 7;
    bar(k);
}

void bar(int m)
{
    cout << m << endl;
}

int factorial(int f)
{
    if(f == 1) return 1;
    else
    {
        return f*factorial(f-1);
    }
}

void ReversePrint(NodeType head)
{
    if(head != NULL)
    {
        ReversePrint(head->link);
        cout << head->component << endl;
    }
}

void printn(int n)
{
    if(n < 0) return;
    else
    {
        cout << " " << n << endl;
        printn(n-1);
    }
}


bool Insert(NodeType* item)
{
    currentItem = begin;
    previousItem = NULL;
    moreToSearch = (Length() > 0);
    while(moreToSearch)
    {
        if(currentItem == item)
        {
            return false; // returns false because if it is equal to the current item then there's no reason to add it.
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
        tempNode->next = currentItem;
        previousItem->next = currentItem;
    }
}



bool Insert(NodeType item)
{
    currentItem = begin;
    previousItem = NULL;
    bool moreToSearch = (Length() > 0);
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
        tempNode->next = currentNode;
        previousNode->next = currentNode;
    }
}





bool insert(NodeType item)
{
    currentItem = begin;
    previousItem = NULL;
    bool moretosearch = (Length() > 0);
    while(moretosearch)
    {
        if(currentItem == item)
        {
            return false;
        }
        if(currentItem < item)
        {
            currentItem = previousItem;
            currentItem = currentItem->next;
            moretosearch = (currentItem != NULL);
        }
        if(currentItem > item)
        {
            moretosearch = false;
        }
        NodeType* tempPtr;
        tempPtr->next = currentItem;
        previousItem->next = currentItem;
    }
}