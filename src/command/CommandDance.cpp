#include "CommandDance.h"

#include "../language/Grammar.h"

#include "../util/Sysout.h"

bool CommandDance::execute(gmr::SentenceState* stnc)
{
    Sysout::println("break it down!");

    return true;
}

CommandDance::CommandDance()
{
}
