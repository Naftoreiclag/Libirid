#ifndef COMMANDDANCE_H
#define COMMANDDANCE_H

#include <vector>
#include <string>

#include "Command.h"

#include "../language/Grammar.h"

class CommandDance: public Command
{
    public:
        bool execute(gmr::SentenceState* stnc, std::vector<std::string>* arguementWords, std::string alias);
        CommandDance();
    protected:
    private:
};

#endif // COMMANDDANCE_H
