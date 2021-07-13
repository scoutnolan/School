#include <iostream>
#include "LList.h"

int main() {
    LList list;
    ItemType item;
    list.InsertAsFirst(35);
    list.InsertAsFirst(10);
    list.InsertAsFirst(20);
    list.InsertAsFirst(5);
    list.InsertAsFirst(60);
    list.InsertAsFirst(25);

    list.Print();
    list.Delete(item);
    return 0;
}
