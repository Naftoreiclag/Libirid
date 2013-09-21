#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

#include "../util/Point3i.h"
#include "tree/Tree.h"

class Room
{
    public:
        Point3i getLocation();
        std::string getDescription(int seed);
        void cutDownTree();
        unsigned int numTrees();
        Room(Point3i location);
        virtual ~Room();
    private:
        Point3i location;
        std::vector<Tree*> trees;
};

#endif // ROOM_H
