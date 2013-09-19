#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H

#include <vector>
#include <string>

#include "../../language/Grammar.h"

class Functionality
{
    public:
        virtual bool execute(gmr::SentenceState* stnc, std::vector<std::string>* arguementWords, std::string alias);
    protected:
        Functionality();
};

#endif // FUNCTIONALITY_H
