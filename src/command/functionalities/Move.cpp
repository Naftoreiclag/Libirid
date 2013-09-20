#include "../Functionalities.h"
#include <vector>
#include <string>

#include "../../Fuzzy.h"

#include "../../language/Grammar.h"

#include "../../util/Sysout.h"


bool Move::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    if(argumentWords->size() == 0)
    {
        Sysout::println("Specify a direction.");
    }

    Fuzzy::runningGame->runCommandFromSudoInput("dance");

    if(argumentWords->front() == "north")
    {
        Sysout::println("You moved north.");
    }

    if(argumentWords->front() == "west")
    {
        Sysout::println("You moved west.");
    }

    if(argumentWords->front() == "east")
    {
        Sysout::println("You moved east.");
    }

    if(argumentWords->front() == "south")
    {
        Sysout::println("You moved south.");
    }

    return true;
}

