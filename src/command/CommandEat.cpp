#include "CommandEat.h"

#include "../language/Grammar.h"

#include "../util/Sysout.h"

bool CommandEat::execute(gmr::SentenceState* stnc)
{
    if(stnc->nounStates->size() < 1)
    {
        Sysout::println("You did not eat anything!");
    }

    if(stnc->nounStates->front()->plurality == gmr::singular)
    {
        Sysout::println("You ate a delicious " + stnc->nounStates->front()->getUnmodifiedName() + ".");
    }

    if(stnc->nounStates->front()->plurality == gmr::plural)
    {
        Sysout::println("You ate some delicious " + stnc->nounStates->front()->getUnmodifiedName() + ".");
    }

    return true;
}

CommandEat::CommandEat()
{
}
