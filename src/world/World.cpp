#include "World.h"

#include "Room.h"
#include "../util/Sysout.h"

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
