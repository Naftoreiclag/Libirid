#include "Player.h"

#include "Room.h"

Player::Player(Room* roomLocation)
: amountEaten(0),
roomChangeCount(0),
roomLocation(roomLocation)
{
}

void Player::setRoomLocation(Room* rml)
{
    if(roomLocation != rml)
    {
        ++ roomChangeCount;

        roomLocation = rml;
    }
}

Room* Player::getRoomLocation()
{
    return roomLocation;
}

Player::~Player()
{
}
