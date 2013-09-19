#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <string>

#include "../language/Grammar.h"

class Eat
{
    public:
        static bool execute(gmr::SentenceState* stnc, std::vector<std::string>* arguementWords, std::string alias);
};

class Dance
{
    public:
        static bool execute(gmr::SentenceState* stnc, std::vector<std::string>* arguementWords, std::string alias);
};

#endif // FUNCTIONALITIES_H
