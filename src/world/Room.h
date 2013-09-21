#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

#include "../util/Point3i.h"

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
        virtual ~Room();
    private:
        World* world;
        Point3i worldLocation;
        std::vector<Tree*> trees;
};

#endif // ROOM_H
