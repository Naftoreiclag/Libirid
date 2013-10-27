#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

#include "../util/Point3i.h"

#include "item/Inventory.h"

/*
getFoo() = There is a pointer to an object or primitive on this heap, and you want exactly that
accessFoo() = There is an object stored in this heap, and you want the pointer to it
*/

class World;

class Tree;

class Room
{
    public:
        Point3i getWorldLocation();
        World* getWorld();
        std::string getDescription(int seed);
        void cutDownTree();
        unsigned int numTrees();
        Room(World* world, Point3i worldLocation);
        Inventory* accessInventory();
        virtual ~Room();
    private:
        World* world;
        Inventory inventory;
        Point3i worldLocation;
        std::vector<Tree*> trees;
};

#endif // ROOM_H
