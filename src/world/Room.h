#ifndef ROOM_H
#define ROOM_H

#include <string>

#include "../util/Point3i.h"

class Room
{
    public:
        Point3i getLocation();
        std::string getDescription(int seed);
        Room(Point3i location);
        virtual ~Room();
    protected:
    private:
        Point3i location;
};

#endif // ROOM_H
