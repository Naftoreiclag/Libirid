#include "Inventory.h"

#include "ItemState.h"

#ifdef DEBUG
#include "../../util/Sysout.h"
#endif // DEBUG

//
ItemState* Inventory::accessItem(inv::Slot slot)
{
    #ifdef DEBUG
    if(!(slot < contents.size()))
    {
        Sysout::println("[WARNING] You are trying to access an item from an invalid slot! Probably will crash!");
    }
    #endif // DEBUG
    return contents.at(slot);
}

//
ItemState* Inventory::takeItem(inv::Slot slot)
{
    #ifdef DEBUG
    if(!(slot < contents.size()))
    {
        Sysout::println("[WARNING] You are trying to take an item from an invalid slot! Probably will crash!");
    }
    #endif // DEBUG

    // Get the item
    ItemState* gift = contents.at(slot);

    // Remove it from ownership
    contents.erase(contents.begin() + slot);

    // Give it
    return gift;
}

//
inv::Slot Inventory::transferItem(Inventory* giver, inv::Slot takeFrom)
{
    return addItem(giver->takeItem(takeFrom));
}

//
inv::Slot Inventory::addItem(ItemState* item)
{
    contents.push_back(item);

    return contents.size() - 1;
}

//
unsigned int Inventory::size()
{
    return contents.size();
}

// Constructor
Inventory::Inventory()
{
}

// De-constructor
Inventory::~Inventory()
{
    // Iterate through contents
    for(std::vector<ItemState*>::iterator it = contents.begin(); it != contents.end(); ++ it)
    {
        // Delete them
        delete *it;
    }
}
