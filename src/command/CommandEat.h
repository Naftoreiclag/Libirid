#ifndef COMMANDEAT_H
#define COMMANDEAT_H

#include <vector>
#include <string>

#include "Command.h"

#include "../language/Grammar.h"

class CommandEat: public Command
{
    public:
        bool execute(gmr::SentenceState* stnc, std::vector<std::string>* arguementWords, std::string alias);
        CommandEat();
    protected:
    private:
};

#endif // COMMANDEAT_H
