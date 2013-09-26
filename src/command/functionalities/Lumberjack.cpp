#include "../Functionalities.h"

#include "../../language/Grammar.h"

#include "../../util/Sysout.h"

#include "../../Fuzzy.h"

#include <vector>
#include <string>


#include "../../world/Player.h"
#include "../../world/Room.h"

bool Lumberjack::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    Sysout::println("chop");
    Sysout::println();

    Room* room = Fuzzy::runningGame->player->getRoomLocation();

    room->cutDownTree();

    return true;
}
