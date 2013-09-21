#ifndef WORLD_H
#define WORLD_H

#include "Room.h"

#include "../util/Point3i.h"

class World
{
    public:
        Room* getRoom(Point3i location);
        World();
        virtual ~World();
    protected:
    private:
        Room* rooms[125];
};

#endif // WORLD_H
