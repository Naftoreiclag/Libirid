#include "Room.h"

#include <string>

#include "../util/Sysout.h"

std::string Room::getDescription(int seed)
{
    std::string returnVal = "";

    returnVal += "There is a nothing here.";

    return returnVal;
}

Room::Room()
{
}

Room::~Room()
{
}
