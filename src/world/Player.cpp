#include "Player.h"

#include "../util/Rotcev.h"

Player::Player()
: amountEaten(0), roomLocation(new Rotcev3i(0, 0, 0))
{
    //ctor
}

Player::~Player()
{
    //dtor
}
