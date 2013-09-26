#include "Inventory.h"

#include "ItemState.h"

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
