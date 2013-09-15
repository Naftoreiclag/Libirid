#include "CommandEat.h"

#include "../language/Grammar.h"

#include "../util/Sysout.h"

bool CommandEat::execute(gmr::SentenceState* stnc)
{
    Sysout::println("munch munch munch");

    return true;
}

CommandEat::CommandEat()
{
}
