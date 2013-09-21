#include "Player.h"

#include "../util/Point3i.h"

Player::Player()
: amountEaten(0), roomLocation(new Point3i(0, 0, 0))
{
    //ctor
}

Player::~Player()
{
    //dtor
}
