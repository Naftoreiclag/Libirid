#include "Room.h"

#include <string>

#include "../util/Sysout.h"
#include "../util/Point3i.h"

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
    returnVal += Sysout::toFriendlyString(location);
    returnVal += " It has ";
    returnVal += Sysout::toString(numTrees());
    returnVal += " trees.";

    return returnVal;
}

Point3i Room::getLocation()
{
    return location;
}

Room::Room(Point3i location)
: location(location)
{
    trees.push_back(new Tree());
    trees.push_back(new Tree());
    trees.push_back(new Tree());
}

Room::~Room()
{
}
