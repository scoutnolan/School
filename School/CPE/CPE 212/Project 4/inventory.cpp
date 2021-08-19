#include "inventory.hpp"

void Inventory::Add(const Item &i)
{
    if(length != 32)
    {
        contents.AddItemSorted(i);
        length++;
    }
    /**
     * Add the item to the inventory
     */
}

bool Inventory::Remove(const Item &i)
{
    if(contents.DeleteItem(i))
    {
        return true;
    }
    return false;
    /**
     * Delete the item from the inventory
     */
}

bool Inventory::isEmpty() const
{
    return(length == 0);
    /**
     * Return if the inventory is empty
     */
}
bool Inventory::isFull() const
{
    return(length == maxSize);
    /**
     * Return if the inventory is full
     */
}
void Inventory::ShowInventory() const
{
    PrintHeader();  // Leave this here

    contents.ResetIterator();
    while(!contents.AtEnd())
    {
        PrintItem(contents.IterateItems());
    }
    contents.ResetIterator();
    /**
     * Print out the contents of the inventory. Use the PrintItem helper function below
     */
    PrintFooter();  // Leave this here
}

Item Inventory::PopFront() 
{
    length--;
    return contents.PopFront();
    /**
     * Pop the first item off of the inventory and return it back to the caller
     */
}

/**
 * DO NOT MODIFY
 * @param i {Item*}
 */
void Inventory::PrintItem(Item *i) const
{
    if(i == nullptr)
    {
        std::cout << "ITEM IS NULL" << std::endl;
        return;
    }
    // Formatting the output into a table
    std::cout << std::left
              << std::setw(10)
              << i->GetType();
    std::cout
              << std::setw(35)
              << i->GetName();
    std::cout
              << std::setw(7)
              << i->GetValue()
              << std::endl;
}
