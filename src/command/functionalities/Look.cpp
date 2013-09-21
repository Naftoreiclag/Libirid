#include "../Functionalities.h"
#include <vector>
#include <string>

#include "../../Fuzzy.h"

#include "../../language/Grammar.h"

#include "../../util/Sysout.h"

bool Look::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    Player* player = Fuzzy::runningGame->player;
    World* world = Fuzzy::runningGame->world;

    Sysout::d_println(Sysout::toFriendlyString(player->roomLocation->getWorldLocation()));

    Sysout::println(Sysout::wordWrappify(player->roomLocation->getDescription(0)));

    return true;
}

