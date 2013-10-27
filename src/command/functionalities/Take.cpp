#include "../Functionalities.h"

#include "../../language/Grammar.h"

#include "../../Fuzzy.h"

#include "../../world/Player.h"

#include "../../world/Room.h"
#include "../../world/item/Inventory.h"

#include "../../util/Sysout.h"

#include <vector>
#include <string>

bool Take::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    // Check context for any items that match the object mentioned
    // Maybe a list of functions, similar to the command function list, to run based on noun lookup?

    //
    if(stnc->nounStates->size() == 0)
    {
        //
        Sysout::println("You take nothing.");

        return true;
    }

    Player* p = Fuzzy::runningGame->player;

    Room* r = p->getRoomLocation();

    Inventory* ri = r->accessInventory();
    Inventory* pi = p->accessInventory();

    pi->transferItem(ri, 0);

    //gmr::NounState* object = stnc->nounStates->front();

    //Player* p = Fuzzy::runningGame->player;

    //p->inventory->transferItem();

    return true;
}

