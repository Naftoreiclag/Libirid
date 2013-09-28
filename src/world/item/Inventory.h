#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

class ItemState;

namespace inv
{
    typedef unsigned int Slot;
}

// Better than a typedef for a vector, since we can clean up the
// pointers on deletion!

class Inventory
{
    public:
        // Get access to the item
        ItemState* accessItem(inv::Slot slot);

        // Literally take the item from the inventory
        ItemState* takeItem(inv::Slot slot);

        // Transfer the item from one inventory to this one
        inv::Slot transferItem(Inventory* giver, inv::Slot takeFrom);

        // Add an item
        inv::Slot addItem(ItemState* item);

        //
        unsigned int size();

        Inventory();
        ~Inventory();
    private:
        std::vector<ItemState*> contents;

};

#endif // INVENTORY_H
