#include "../Functionalities.h"

#include "../../language/Grammar.h"

#include "../../util/Sysout.h"

#include "../../Fuzzy.h"

#include <vector>
#include <string>

bool Lumberjack::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    Sysout::println("chop");

    Room* room = Fuzzy::runningGame->player->roomLocation;

    room->cutDownTree();

    return true;
}

