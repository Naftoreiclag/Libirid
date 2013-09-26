#include "../Functionalities.h"
#include <vector>
#include <string>

#include "../../Fuzzy.h"

#include "../../language/Grammar.h"

#include "../../util/Sysout.h"

#include "../../world/Player.h"

#include "../../world/Room.h"

bool Look::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    Player* player = Fuzzy::runningGame->player;

    #ifdef DEBUG
    Sysout::print("Player location: ");
    Sysout::println(Sysout::toFriendlyString(player->getRoomLocation()->getWorldLocation()));
    #endif

    Sysout::println(Sysout::wordWrappify(player->getRoomLocation()->getDescription(player->roomChangeCount)));

    return true;
}

