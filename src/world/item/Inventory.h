#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

class ItemState;

// Better than a typedef for a vector, since we can clean up the
// pointers on deletion!

class Inventory
{
    public:
        Inventory();
        ~Inventory();
    private:
        std::vector<ItemState*> contents;

};

#endif // INVENTORY_H
