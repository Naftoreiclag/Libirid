#ifndef PLAYER_H
#define PLAYER_H

class Room;

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
