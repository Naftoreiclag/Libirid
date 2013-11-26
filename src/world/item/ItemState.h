#ifndef ITEMSTATE_H
#define ITEMSTATE_H

#include "ItemDefinition.h"

class Inventory;

class ItemState
{
    public:
        ItemState(itm::ItemDefId definitionId);
        ItemDefinition* accessDefinition();
        virtual ~ItemState();
    private:
        itm::ItemDefId definition;
        Inventory* owner;
};

#endif // ITEMSTATE_H
