#ifndef PLAYER_H
#define PLAYER_H

#include "../util/Point3i.h"

class Player
{
    public:
        unsigned int amountEaten;
        Point3i* roomLocation;
        Player();
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
