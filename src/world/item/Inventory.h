#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

class ItemDefinition;

// Better than a typedef for a vector, since we can clean up the
// pointers on deletion!

class Inventory
{
    public:
        Inventory();
        virtual ~Inventory();
    private:
        std::vector<ItemDefinition> contents;

};

#endif // INVENTORY_H
