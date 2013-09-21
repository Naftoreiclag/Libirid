#include "Player.h"

#include "Room.h"

Player::Player(Room* roomLocation)
: amountEaten(0), roomLocation(roomLocation)
{
    //ctor
}

Player::~Player()
{
    //dtor
}
