#ifndef PLAYER_H
#define PLAYER_H

#include "Room.h"

class Player
{
    public:
        unsigned int amountEaten;
        Room* roomLocation;
        Player(Room* roomLocation);
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
