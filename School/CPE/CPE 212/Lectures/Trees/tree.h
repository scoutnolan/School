/* 
** Binary Search Tree implementation in C++
*/
#include <iostream>
#include <new>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {

    private:
        Node* root;

        Node* makeEmpty(Node* t);
        Node* insert(int x, Node* t);
        Node* remove(int x, Node* t);
        Node* find(int x, Node* t);
        Node* findMin(Node* t);
        Node* findMax(Node* t);
        void inorder(Node* t);
        int countNodes(Node* t);

    public:
        BST();
        ~BST();

        void insert(int x);
        void remove(int x);
        void display();

        void search(int x);
        int lengthIs();

        bool makeEmpty();
        bool isEmpty() const;
        bool isFull() const;
};

