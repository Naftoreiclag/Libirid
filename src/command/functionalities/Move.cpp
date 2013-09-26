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

    // If we are actually moving
    if(directionVector != Point3i(0, 0, 0))
    {
        // Tell
        Sysout::print("You travel "); Sysout::print(argumentWords->front()); Sysout::println(".");

        // Get objects
        Player* player = Fuzzy::runningGame->player;
        Point3i playerWorldLocation = player->getRoomLocation()->getWorldLocation();
        World* world = player->getRoomLocation()->getWorld();

        // Move
        player->setRoomLocation(world->getRoom(playerWorldLocation + directionVector));

        // Sudo-run the look command
        Fuzzy::runningGame->runCommandFromSudoInput("look");

        // Successful
        return true;
    }

    // Also works like "do"
    /*if(alias == "go")
    {
        // Test the command
        bool subCmdSuccess = Fuzzy::runningGame->runCommandFromRawInput(argumentWords);

        // If successful
        if(subCmdSuccess)
        {
            // Successful
            return true;
        }
    }*/

    #ifdef DEBUG
    if(alias == "go")
    {
        Sysout::println("'Move' was called by the 'go' alias.");
    }
    #endif

    // Fail
    return false;
}

