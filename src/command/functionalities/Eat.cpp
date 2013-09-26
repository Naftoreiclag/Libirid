#include "../Functionalities.h"

#include "../../language/Grammar.h"

#include "../../util/Sysout.h"

#include "../../Fuzzy.h"

#include "../../world/Player.h"

#include <vector>
#include <string>

bool Eat::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    if(stnc->nounStates->size() < 1)
    {
        Sysout::println("You did not eat anything!");
        Sysout::println();

        return true;
    }

    if(stnc->nounStates->front()->plurality == gmr::singular)
    {
        if(stnc->nounStates->front()->definity == gmr::definite)
        {
            Sysout::println("You ate the delicious " + stnc->nounStates->front()->getUnmodifiedName() + ".");
        }
        else
        {
            Sysout::println("You ate a delicious " + stnc->nounStates->front()->getUnmodifiedName() + ".");
        }
    }

    if(stnc->nounStates->front()->plurality == gmr::plural)
    {
        if(stnc->nounStates->front()->definity == gmr::definite)
        {
            Sysout::println("You ate the delicious " + stnc->nounStates->front()->getUnmodifiedName() + ".");
        }
        else
        {
            Sysout::println("You ate some delicious " + stnc->nounStates->front()->getUnmodifiedName() + ".");
        }
    }

    ++ Fuzzy::runningGame->player->amountEaten;

    Sysout::print("You have now eaten: "); Sysout::print(Fuzzy::runningGame->player->amountEaten); Sysout::println(" foodstuffs!");

    Sysout::println();

    return true;
}
