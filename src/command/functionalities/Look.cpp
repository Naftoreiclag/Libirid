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

    Sysout::d_println(Sysout::toFriendlyString(player->roomLocation->getWorldLocation()));

    Sysout::println(Sysout::wordWrappify(player->roomLocation->getDescription(0)));

    return true;
}

