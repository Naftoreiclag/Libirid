#include "Tree.h"

#include "../item/Inventory.h"

Tree::Tree()
{
    inventory = new Inventory();
}

Tree::~Tree()
{
    delete inventory;
}
