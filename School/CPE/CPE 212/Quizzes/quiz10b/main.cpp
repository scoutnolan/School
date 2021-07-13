#include "tree.h"
#include <iostream>

int main() {
    BST t;
    // std::cout << std::boolalpha << "Is Empty? " << t.isEmpty() << std::endl;
    // std::cout << std::boolalpha << "Is Empty? " << t.isEmpty() << std::endl;
    // std::cout << std::boolalpha << "Is Full? " << t.isFull() << std::endl;
    // std::cout << "Length is: " << t.lengthIs() << std::endl;
    // t.display();
    // // Remove 6
    // t.remove(6);
    // t.display();

    cout << endl;
    //inserting 4 then 6 then 8
    cout << "''''''''Left Rotation''''''''" << endl;
    t.insert(4);
    t.insert(6);
    t.insert(8);
    cout << endl << "Original Tree:" << endl;
    t.display_tree();
    cout << endl << endl;
    cout << "Rotating tree.... (LEFT)" << endl;
    t.leftrotate(4);
    t.display();
    t.remove(4);
    t.remove(6);
    t.remove(8);

    cout << endl << "______________________________________________";
    cout << endl << endl;
    cout << "''''''''Right Rotation''''''''" << endl;
    // inserting 8 then 6 then 4
    t.insert(8);
    t.insert(6);
    t.insert(4);
    cout << endl << "Original Tree:" << endl;
    t.display_tree();
    cout << endl << endl;
    cout << "Rotating tree.... (RIGHT)" << endl;
    t.rightrotate(8);
    t.display();
    t.remove(4);
    t.remove(6);
    t.remove(8);

    cout << endl << "______________________________________________";
    cout << endl << endl;
    cout << "''''''''Right Left Rotation''''''''" << endl;
    // inserting 4 then 8 then 6
    t.insert(4);
    t.insert(8);
    t.insert(6);
    cout << endl << "Original Tree:" << endl;
    t.display_tree();
    cout << endl << endl;
    cout << "Rotating tree.... (RIGHT LEFT)" << endl;
    t.rightleft(4);
    t.display();
    t.remove(4);
    t.remove(6);
    t.remove(8);
    cout << endl << "______________________________________________";
    cout << endl << endl;
    cout << "''''''''Left Right Rotation''''''''" << endl;
    // inserting 8, then 4, then 6
    t.insert(8);
    t.insert(4);
    t.insert(6);
    cout << endl << "Original Tree:" << endl;
    t.display_tree();
    cout << endl << endl;
    cout << "Rotating tree.... (LEFT RIGHT)" << endl;
    t.leftright(8);
    t.display();
    t.remove(4);
    t.remove(6);
    t.remove(8);


    cout << endl;
    return 0; 
}