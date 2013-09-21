#include "../Functionalities.h"

#include "../../language/Grammar.h"

#include "../../Fuzzy.h"

#include <vector>
#include <string>

bool Do::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    return Fuzzy::runningGame->runCommandFromRawInput(argumentWords);
}

