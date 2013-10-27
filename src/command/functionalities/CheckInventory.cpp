#include "../Functionalities.h"

#include "../../language/Grammar.h"

#include "../../util/Sysout.h"

#include <vector>
#include <string>

#include "../../Fuzzy.h"
#include "../../world/Player.h"

bool CheckInventory::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    Sysout::println("Inventory Size: ");

    Sysout::println(Sysout::toString(Fuzzy::runningGame->player->accessInventory()->size()));

    Sysout::println("Inventory Contents: ");
    Sysout::println();

    return true;
}

