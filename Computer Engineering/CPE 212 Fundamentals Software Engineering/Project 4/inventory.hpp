#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "list.hpp"
#include "item.h"

class Inventory
{
private:
    int length = 0;
    unsigned int maxSize = 32;
    List<Item> contents;
public:
    Inventory() = default;

    void Add(const Item &i);
    bool Remove(const Item &i);
    bool isEmpty() const;
    bool isFull() const;
    void ShowInventory() const;
    void PrintItem(Item *i) const;
    Item PopFront();

    // Provided Formatters
    void PrintHeader() const
    {
        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "                      Inventory Screen " << std::endl;
        std::cout << "--------------------------------------------------------------------" << std::endl;
        std::cout << "Type      Name                              Value " << std::endl;
        std::cout << "--------------------------------------------------------------------" << std::endl;
    }

    void PrintFooter() const
    {
        std::cout << "--------------------------------------------------------------------" << std::endl;
    }
};

#endif