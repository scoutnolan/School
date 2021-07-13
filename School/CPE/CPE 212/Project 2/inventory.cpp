#include "inventory.hpp"

/**
 * Inventory Constructor
 * Add the following item to the inventory
 * Item:
 *  name : "Basic Health Potion"
 *  value: 10
 *  type: POTION
 */
Inventory::Inventory(){
    Item item;
    item.name = "Basic Health Potion";
    item.value = 10;
    item.type = POTION;
    length = 0;
    AddToInventory(item);
}


void Inventory::AddToInventory(Item item){
    //Item item;
    items[length] = item;
    length++;
}

void Inventory::ShowInventory(){
    for(int i = 0; i < length; i++)
    {
        cout << "Item - " << items[i].name << " Value: " << items[i].value << endl;
    }
}

/**
 * AddToInventory Function
 * Function that adds items to the inventory
 */ 

/*a*
 * ShowInventory Function
 * Function that shows all items in the inventory
 * @attention Make sure that you format the output string as follows:
 *  Item - <Item Name> Value: <Item Value>
 */ 