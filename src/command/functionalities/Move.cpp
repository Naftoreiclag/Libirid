#include "../Functionalities.h"
#include <vector>
#include <string>

#include "../../Fuzzy.h"

#include "../../language/Grammar.h"

#include "../../util/Point3i.h"
#include "../../util/Sysout.h"

#include "../../world/World.h"
#include "../../world/Player.h"
#include "../../world/Room.h"

bool Move::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    if(argumentWords->size() == 0)
    {
        Sysout::println("Specify a direction.");

        return false;
    }

    Player* player = Fuzzy::runningGame->player;
    Point3i playerWorldLocation = player->getRoomLocation()->getWorldLocation();
    World* world = player->getRoomLocation()->getWorld();

    if(argumentWords->front() == "east")
    {
        Sysout::println("You moved east.");

        player->setRoomLocation(world->getRoom(playerWorldLocation + Point3i(1, 0, 0)));
    }

    if(argumentWords->front() == "west")
    {
        Sysout::println("You moved west.");

        player->setRoomLocation(world->getRoom(playerWorldLocation + Point3i(-1, 0, 0)));
    }

    if(argumentWords->front() == "south")
    {
        Sysout::println("You moved south.");

        player->setRoomLocation(world->getRoom(playerWorldLocation + Point3i(0, 0, 1)));
    }

    if(argumentWords->front() == "north")
    {
        Sysout::println("You moved north.");

        player->setRoomLocation(world->getRoom(playerWorldLocation + Point3i(0, 0, -1)));
    }

    Fuzzy::runningGame->runCommandFromSudoInput("look");

    return true;
}

