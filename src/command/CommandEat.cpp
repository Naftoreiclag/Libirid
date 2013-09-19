#include "CommandEat.h"

#include "../language/Grammar.h"

#include "../util/Sysout.h"

bool CommandEat::execute(gmr::SentenceState* stnc)
{
    if(stnc->nounStates->size() < 1)
    {
        Sysout::println("You did not eat anything!");

        return false;
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

    return true;
}

CommandEat::CommandEat()
{
}
