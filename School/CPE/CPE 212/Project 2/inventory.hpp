#include <string>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef INVENTORY_H
#define INVENTORY_H

const unsigned int MAX_SLOTS = 10;

enum Type
{
    POTION = 0,
    WEAPON = 1,
    ARMOR = 2,
    ACCESSORY = 3
};

struct Item
{
    string name;
    float value;
    Type type;
};


class Inventory
{
private:
    Item items[MAX_SLOTS];
    int length;
public:
    Inventory();
    void AddToInventory(Item i);
    void ShowInventory();
};

#endif