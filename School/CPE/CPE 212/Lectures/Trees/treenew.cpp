Node* BST::makeEmpty(Node* t)
{
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


Node* BST::findMax(Node* t)
{
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




void BST::inorder(Node* t)
{
    if(t == NULL)
        return NULL;
    inorder(t->left);
    cout << t->data << " ";
    inorder(t->right);
}



Node* BST::find(int x, Node* t)
{
    if(t == NULL)
        return NULL;
    else if(x < t->data)
        return find(x, t->left);
    else if(x > t->data)
        return find(x, t->right);
    else    
        return t;
}


int BST::countNodes(Node* t)
{
    if(t == NULL)
        return 0;
    else
        return (countNodes(t->left) + countNodes(t->right) + 1);
}


BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    root =  makeEmpty(root);
}


void BST::insert(int x)
{
    root = insert(x, root);
}


void BST::remove(int x)
{
    root = remove(x, root);
}


void BST::display()
{
    inorder(root);
    cout << endl;
}



void BST::search(int x)
{   
    root =  find(x, root);
}


int BST::legnthIs()
{
    return countNodes(root);
}


bool BST::isEmpty() const
{
    return (root == NULL);
}


bool BST::isFull() const
{
    Node* location;
    try
    {
        location = new node;
        delete location;
        return false;
    }
    catch( bad_alloc )
    {
        return true;
    }
}



void printInorder(struct Node* node)
{
    if(node == NULL)
        return;
    printInorder(node->left);
    cout << node->data;
    printInorder(data->right);
}


void printPreorder(struct Node* node)
{
    if(node == NULL)
        return;
    cout << node->data << endl;
    printPreorder(node->left);
    printPreorder(node->right);
}



void printPostorder(struct Node* node)
{
    if(node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << endl;
}