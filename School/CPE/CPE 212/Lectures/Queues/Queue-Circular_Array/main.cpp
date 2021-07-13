#include "queue.h"
#include <iostream>

int main() {
    Queue q;
    std::cout << std::boolalpha << "Queue Empty? " << q.IsEmpty() << "\n";
    q.Enqueue('H');
    q.Enqueue('e');
    q.Enqueue('l');
    q.Enqueue('l');
    q.Enqueue('o');
    std::cout << std::boolalpha << "Queue Empty? " << q.IsEmpty() << "\n";
    std::cout << std::boolalpha << "Queue Full? " << q.IsFull() << "\n";
    return 0;
}