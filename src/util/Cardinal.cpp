#include "Cardinal.h"

#include <string>

#include "Point3i.h"

Point3i Cardinal::interpretString(std::string str)
{
    if(str == "east")
    {
        return Point3i(1, 0, 0);
    }

    if(str == "west")
    {
        return Point3i(-1, 0, 0);
    }

    if(str == "south")
    {
        return Point3i(0, 0, 1);
    }

    if(str == "north")
    {
        return Point3i(0, 0, -1);
    }

    return Point3i(0, 0, 0);
}