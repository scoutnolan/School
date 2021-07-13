#include "heap.hpp"
#include <iostream>
using namespace std;
// Driver program to test the heap
int main()
{
    MinHeap h(11);
    h.insertKey(25);
    h.insertKey(14);
    h.print();
    //h.deleteKey(1);
    cout << "Deleting the Key 1" << endl;
    h.print();
    h.insertKey(15);

    h.insertKey(5);

    h.insertKey(4);

    h.insertKey(45);
    h.print();
    cout << h.extractMin() << " \n";
    cout << h.getMin() << " \n";
    h.decreaseKey(2, 1);
    cout << h.getMin() << endl;
    return 0;
}