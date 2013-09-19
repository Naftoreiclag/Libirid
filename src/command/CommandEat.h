#ifndef COMMANDEAT_H
#define COMMANDEAT_H

#include <vector>
#include <string>

#include "../language/Grammar.h"

class CommandEat
{
    public:
        static bool execute(gmr::SentenceState* stnc, std::vector<std::string>* arguementWords, std::string alias);
};

#endif // COMMANDEAT_H
