#ifndef PLAYER_H
#define PLAYER_H

#include "item/Inventory.h"

class Room;

class Player
{
    public:
        unsigned int amountEaten;
        unsigned int roomChangeCount;
        void setRoomLocation(Room* roomLocation);
        Inventory* accessInventory();
        Room* getRoomLocation();
        Player(Room* roomLocation);
        virtual ~Player();
    private:
        Inventory inventory;
        Room* roomLocation;
};

#endif // PLAYER_H
