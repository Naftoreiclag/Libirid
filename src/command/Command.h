#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include <string>

#include "../language/Grammar.h"

class Command
{
    public:
        virtual bool execute(gmr::SentenceState* stnc, std::vector<std::string>* arguementWords, std::string alias);
    protected:
        Command();
};

#endif // COMMAND_H
