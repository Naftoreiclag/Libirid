#include "World.h"

#include "Room.h"
#include "../util/Sysout.h"

Room* World::getRoom(Point3i location)
{
    return rooms[(location.x) + (location.y * 5) + (location.z * 25)];
}

World::World()
{
    for(unsigned int index = 0; index < 125; ++ index)
    {
        rooms[index] = new Room();
    }
}

World::~World()
{
    for(unsigned int index = 0; index < 125; ++ index)
    {
        delete rooms[index];
    }
}
