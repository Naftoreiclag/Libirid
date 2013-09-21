#ifndef WORLD_H
#define WORLD_H

#include "Room.h"

#include "../util/Point3i.h"

class World
{
    public:
        Room* getRoom(Point3i location);
        int packCoord(int x, int y, int z);
        World();
        virtual ~World();
    protected:
    private:
        Room* rooms[1000];
};

#endif // WORLD_H
