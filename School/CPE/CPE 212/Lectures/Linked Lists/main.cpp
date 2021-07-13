#include <iostream>
#include "LList.h"

int main() {
    LList list;



    list.InsertAsFirst(20);
    list.InsertAsFirst(40);
    /*list.Insert(35);
    list.Insert(10);
    list.Insert(20);
    list.Insert(5);
    list.Insert(60);
    list.Insert(25);*/

    list.Print();

    return 0;
}
