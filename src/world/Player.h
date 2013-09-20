#ifndef PLAYER_H
#define PLAYER_H

#include "../util/Rotcev.h"

class Player
{
    public:
        unsigned int amountEaten;
        Rotcev3i* roomLocation;
        Player();
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
