#include<iostream>

using namespace std;

struct node
{
    int num;
    node *link;
    
}*p;


void main()
{
    node *root;

    root = new node;
    root->num=5;
    root->link = p;
    p = root;
    node *q
    for(q=p; q!=NULL; q=q->link)
    {
        cout << q->num;
        cout << endl;
    }
}