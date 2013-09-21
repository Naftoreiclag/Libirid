#include "Room.h"

#include <string>

#include "../util/Sysout.h"
#include "../util/Point3i.h"

std::string Room::getDescription(int seed)
{
    std::string returnVal = "";

    returnVal += "This room is located at: ";
    returnVal += Sysout::toFriendlyString(location);

    return returnVal;
}

Point3i Room::getLocation()
{
    return location;
}

Room::Room(Point3i location)
: location(location)
{
}

Room::~Room()
{
}
