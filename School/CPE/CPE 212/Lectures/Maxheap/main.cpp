#include "maxheap.hpp"
#include <iostream>
using namespace std;
// Driver program to test the heap
int main()
{
    MaxHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.print();
    h.deleteKey(1);
    cout << "Deleting the Key 1" << endl;
    h.print();
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    h.print();
    cout << h.extractMax() << " \n";
    cout << h.getMax() << " \n";
    h.decreaseKey(2, 1);
    cout << h.getMax() << endl;
    return 0;
}