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
        ItemState* takeItem(Slot slot)
        void addItem(ItemState* item);

        Inventory();
        ~Inventory();
    private:
        std::vector<ItemState*> contents;

};

#endif // INVENTORY_H
