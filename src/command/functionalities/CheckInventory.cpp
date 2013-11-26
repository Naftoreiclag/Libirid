#include "../Functionalities.h"

#include "../../language/Grammar.h"

#include "../../util/Sysout.h"

#include <vector>
#include <string>

#include "../../Libirid.h"
#include "../../world/Player.h"
#include "../../world/item/ItemState.h"

bool CheckInventory::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    Inventory* inventory = Libirid::runningGame->player->accessInventory();

    Sysout::println("Inventory Size: ");

    Sysout::println(Sysout::toString(inventory->size()));

    Sysout::println("Inventory Contents: ");
    Sysout::println();

    for(inv::Slot slotcheck = 0; slotcheck < inventory->size(); ++ slotcheck)
    {
        Sysout::println(inventory->accessItem(slotcheck)->accessDefinition()->numNames());
    }

    Sysout::println();

    return true;
}

