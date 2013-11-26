#include "../Functionalities.h"

#include "../../language/Grammar.h"

#include "../../Libirid.h"

#include <vector>
#include <string>

bool Do::execute(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias)
{
    return Libirid::runningGame->runCommandFromRawInput(argumentWords);
}
