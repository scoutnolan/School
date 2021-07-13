#include "tree.h"
#include <iostream>

int main() {
    BST t;
    std::cout << std::boolalpha << "Is Empty? " << t.isEmpty() << std::endl;
    t.insert(8);
    t.insert(3);
    t.insert(1);
    t.insert(10);
    t.insert(6);
    t.insert(14);
    t.insert(4);
    t.insert(7);
    t.insert(13);
    std::cout << std::boolalpha << "Is Empty? " << t.isEmpty() << std::endl;
    std::cout << std::boolalpha << "Is Full? " << t.isFull() << std::endl;
    std::cout << "Length is: " << t.lengthIs() << std::endl;
    t.display();
    // Remove 6
    t.remove(6);
    t.display();
    return 0; 
}