#include "../Functionalities.h"
#include <vector>
#include <string>

#include "../../Fuzzy.h"

#include "../../language/Grammar.h"

#include "../../util/Point3i.h"
#include "../../util/Cardinal.h"
#include "../../util/Sysout.h"

#include "../../world/World.h"
#include "../../world/Player.h"
#include "../../world/Room.h"

bool Move::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    // If there are no arguments, tell the user how to do it
    if(argumentWords->size() == 0)
    {
        // Inform
        Sysout::println("Specify a direction.");

        // Fail
        return false;
    }

    // Vector to store direction
    Point3i directionVector = Cardinal::interpretString(argumentWords->front());

    if(directionVector != Point3i(0, 0, 0))
    {
        Sysout::print("You moved "); Sysout::print(argumentWords->front()); Sysout::println(".");

        Player* player = Fuzzy::runningGame->player;
        Point3i playerWorldLocation = player->getRoomLocation()->getWorldLocation();
        World* world = player->getRoomLocation()->getWorld();

        player->setRoomLocation(world->getRoom(playerWorldLocation + directionVector));
        Fuzzy::runningGame->runCommandFromSudoInput("look");

        return true;
    }

    if(alias == "go")
    {
        bool subCmdSuccess = Fuzzy::runningGame->runCommandFromRawInput(argumentWords);

        if(subCmdSuccess)
        {
            return true;
        }
    }

    return false;
}

