#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

#include "../util/Point3i.h"
#include "tree/Tree.h"

class World;

class Room
{
    public:
        Point3i getWorldLocation();
        World* getWorld();
        std::string getDescription(int seed);
        void cutDownTree();
        unsigned int numTrees();
        Room(World* world, Point3i worldLocation);
        virtual ~Room();
    private:
        Point3i worldLocation;
        World* world;
        std::vector<Tree*> trees;
};

#endif // ROOM_H
