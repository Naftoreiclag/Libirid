#include "World.h"

#include "Room.h"
#include "../util/Sysout.h"

Room* World::getRoom(Point3i location)
{
    return rooms[packCoord(location.x, location.y, location.z)];
}

int World::packCoord(int x, int y, int z)
{
    return x + (y * 10) + (z * 100);
}

World::World()
{
    for(unsigned int x = 0; x < 10; ++ x)
    {
        for(unsigned int y = 0; y < 10; ++ y)
        {
            for(unsigned int z = 0; z < 10; ++ z)
            {
                rooms[World::packCoord(x, y, z)] = new Room(this, Point3i(x, y, z));
            }
        }
    }
}

World::~World()
{
    /*for(unsigned int index = 0; index < 125; ++ index)
    {
        delete rooms[index];
    }*/
}
