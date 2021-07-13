#include "tree.h"
#include <iostream>

int main() {
    BST t;
    std::cout << std::boolalpha << "Is Empty? " << t.isEmpty() << std::endl;
    // t.insert(8);                        // this will become the root
    // t.insert(3);                        // left of 8
    // t.insert(1);                        // left of 3
    // t.insert(10);                       // right of 8
    // t.insert(6);                        // right of 3
    // t.insert(14);                       // right of 10
    // t.insert(4);                        // left of 6
    // t.insert(7);                        // right of 6
    // t.insert(13);                       // left of 14

t.insert(15);

t.insert(7);

t.insert(9);

t.insert(21);

t.insert(44);

t.insert(30);

t.insert(33);

t.insert(29);
t.insert(10);
t.insert(1);
t.insert(17);
t.display();

    std::cout << std::boolalpha << "Is Empty? " << t.isEmpty() << std::endl;
    std::cout << std::boolalpha << "Is Full? " << t.isFull() << std::endl;
    std::cout << "Length is: " << t.lengthIs() << std::endl;
    t.display();
    // Remove 6
    //t.remove(6);
    //t.display();
    return 0; 
}