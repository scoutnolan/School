#include <string>
#include <iostream>

template<typename NodeType>
struct Node
{
    NodeType data;
    Node<NodeType> *nextNode;

    Node(const NodeType d)
    {
        data = d;
        nextNode = NULL;
    }
};


template<int count>
struct Items
{
    int MyItems[count];
};


int main()
{
    Node<int> intNode(1);
    Node<float> floatNode(1.1f);
    Node<std::string> stringNode("Hello world");

    // Node injectedNode(10.0f);

    // std::cout << injectedNode.data << std::endl;


    Items<200> itemData;
}
