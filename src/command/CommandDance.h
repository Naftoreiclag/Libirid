#ifndef COMMANDDANCE_H
#define COMMANDDANCE_H

#include <vector>
#include <string>

#include "../language/Grammar.h"

class CommandDance
{
    public:
        static bool execute(gmr::SentenceState* stnc, std::vector<std::string>* arguementWords, std::string alias);
};

#endif // COMMANDDANCE_H
