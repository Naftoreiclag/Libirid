#include "../Functionalities.h"
#include <vector>
#include <string>

#include "../../Fuzzy.h"

#include "../../language/Grammar.h"

#include "../../util/Sysout.h"

bool Move::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    if(argumentWords->size() == 0)
    {
        Sysout::println("Specify a direction.");
    }

    Player* player = Fuzzy::runningGame->player;

    if(argumentWords->front() == "west")
    {
        Sysout::println("You moved west.");

        -- player->roomLocation->x;
    }

    if(argumentWords->front() == "east")
    {
        Sysout::println("You moved east.");

        ++ player->roomLocation->x;
    }

    if(argumentWords->front() == "south")
    {
        Sysout::println("You moved south.");

        ++ player->roomLocation->z;
    }

    if(argumentWords->front() == "north")
    {
        Sysout::println("You moved north.");

        -- player->roomLocation->z;
    }

    Sysout::d_println(Sysout::toFriendlyString(*player->roomLocation));

    return true;
}

