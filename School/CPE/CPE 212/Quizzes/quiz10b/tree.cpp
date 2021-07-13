/* 
** Binary Search Tree implementation in C++
** Harish R
*/
#include "tree.h"

// Private
Node* BST::makeEmpty(Node* t) {
    if(t == NULL)
        return NULL;
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    return NULL;
}

Node* BST::insert(int x, Node* t)
{
    if(t == NULL)
    {
        t = new Node;
        t->data = x;
        t->left = t->right = NULL;
    }
    else if(x < t->data)
        t->left = insert(x, t->left);
    else if(x > t->data)
        t->right = insert(x, t->right);
    return t;
}

Node* BST::findMin(Node* t)
{
    if(t == NULL)
        return NULL;
    else if(t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

Node* BST::findMax(Node* t) {
    if(t == NULL)
        return NULL;
    else if(t->right == NULL)
        return t;
    else
        return findMax(t->right);
}

Node* BST::remove(int x, Node* t) {
    Node* temp;
    // Base case
    if(t == NULL)
        return NULL;
    // If the data to be deleted is smaller then it is in the left subtree
    if(x < t->data)
        t->left = remove(x, t->left);
    // If the data to be deleted is greater then it is in the right subtree
    else if(x > t->data)
        t->right = remove(x, t->right);
    // If there are two children then get the smallest in the right subtree        
    else if(t->left && t->right)
    {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    }
    // if the data is the same as the t->data then this node needs to be deleted
    else
    {
        temp = t;
        if(t->left == NULL)
            t = t->right;
        else if(t->right == NULL)
            t = t->left;
        delete temp;
    }

    return t;
}

void BST::inorder(Node* t) {
    if(t == NULL)
        return;
    cout << t->data << " ";
    inorder(t->left);
    inorder(t->right);
}

Node* BST::find(int x, Node* t) {
    if(t == NULL)
        return NULL;
    else if(x < t->data)
        return find(x, t->left);
    else if(x > t->data)
        return find(x, t->right);
    else
        return t;
}

int BST::countNodes(Node* t) {
    if (t == NULL) {
        return 0;
    } else {
        return ( countNodes(t->left) + countNodes(t->right) + 1);
    }
}

void BST::display_tree(Node* t, int node)
{
    if(t == NULL)
    {
        return;
    }
    else
    {
        display_tree(t->right, node + 1);
        cout << endl;
        if(t == root)
        {
            cout << "Root: ";
        }
        for (int i = 0; i < node; i++)
        {
            cout << "        ";
        }
        cout << t->data;
        display_tree(t->left, node + 1);
    }
}

void BST::display_tree()
{
    display_tree(root, 0);
}
// Public
BST::BST() {
    root = NULL;
}

BST::~BST() {
    root = makeEmpty(root);
}

void BST::insert(int x) {
    root = insert(x, root);
}

void BST::remove(int x) {
    root = remove(x, root);
}

void BST::display() {
    display_tree(root,0);
}

void BST::search(int x) {
    root = find(x, root);
}

int BST::lengthIs() {
    return countNodes(root);
}

bool BST::isEmpty() const
{
    return (root == NULL);
}

bool BST::isFull() const
{
   Node*  location;
   try
   {
       location = new Node;
       delete  location;
       return false;
   }
   catch( bad_alloc )
   {
       return true;
   }
}

void BST::rightrotate(int n)
{
    root = right(n, root);
}

void BST::leftrotate(int n)
{
    root = left(n, root);
}

Node* BST::right(int x, Node* t)
{
    Node* tmp;
    t->data = x;
    tmp = t->left;
    t->left = tmp->right;
    tmp->right = t;
    return tmp;
}

Node* BST::left(int x, Node* t)
{
    Node* tmp;
    t->data = x;
    tmp = t->right;
    t->right = tmp->left;
    tmp->left = t;
    return tmp;
}
void BST::leftright(int x)
{
    Node* tmp;
    tmp = root->left;
    root->left = left(tmp->data, tmp);
    root = right(x, root);
}

void BST::rightleft(int x)
{
    Node* tmp;
    tmp = root->right;
    root->right = right(tmp->data, tmp);
    root = left(x, root);
}



