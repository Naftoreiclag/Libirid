#ifndef COMMANDDANCE_H
#define COMMANDDANCE_H

#include "Command.h"

#include "../language/Grammar.h"

class CommandDance: public Command
{
    public:
        bool execute(gmr::SentenceState* stnc);
        CommandDance();
    protected:
    private:
};

#endif // COMMANDDANCE_H
