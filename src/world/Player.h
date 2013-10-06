#ifndef PLAYER_H
#define PLAYER_H

class Room;
class Inventory;

class Player
{
    public:
        Inventory* inventory;
        unsigned int amountEaten;
        unsigned int roomChangeCount;
        void setRoomLocation(Room* roomLocation);
        Room* getRoomLocation();
        Player(Room* roomLocation);
        virtual ~Player();
    private:
        Room* roomLocation;
};

#endif // PLAYER_H
