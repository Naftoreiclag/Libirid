#ifndef WORLD_H
#define WORLD_H

#include "Room.h"

class World
{
    public:
        World();
        virtual ~World();
    protected:
    private:
        Room* rooms[125];
};

#endif // WORLD_H
