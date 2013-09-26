#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

#include "ItemDefinition.h"

// Better than a typedef for a vector, since we can clean up the
// pointers on deletion!

class Inventory
{
    public:
        Inventory();
        virtual ~Inventory();
    private:
        std::vector<ItemState*> contents;

};

#endif // INVENTORY_H
