#include "Room.h"

#include <string>

#include "../util/Sysout.h"
#include "../util/Point3i.h"

#include "World.h"

#include "tree/Tree.h"

void Room::cutDownTree()
{
    trees.erase(trees.begin());
}

unsigned int Room::numTrees()
{
    return trees.size();
}

std::string Room::getDescription(int seed)
{
    std::string returnVal = "";

    returnVal += "This room is located at: ";
    returnVal += Sysout::toFriendlyString(worldLocation);
    returnVal += " It has ";
    returnVal += Sysout::toString(numTrees());
    returnVal += " trees.";

    return returnVal;
}

Point3i Room::getWorldLocation()
{
    return worldLocation;
}

World* Room::getWorld()
{
    return world;
}

Room::Room(World* world, Point3i worldLocation)
: world(world), worldLocation(worldLocation)
{
    trees.push_back(new Tree());
    trees.push_back(new Tree());
    trees.push_back(new Tree());
}

Room::~Room()
{
}
