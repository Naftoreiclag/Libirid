#include "CommandAutogen.h"

#include "../language/Grammar.h"

#include "../util/Sysout.h"

bool CommandAutogen::execute(gmr::SentenceState* stnc)
{
    Sysout::println("autogen!");

    return true;
}

CommandAutogen::CommandAutogen()
{
}
