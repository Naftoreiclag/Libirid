#ifndef COMMANDEAT_H
#define COMMANDEAT_H

#include "Command.h"

#include "../language/Grammar.h"

class CommandEat: public Command
{
    public:
        bool execute(gmr::SentenceState* stnc);
        CommandEat();
    protected:
    private:
};

#endif // COMMANDEAT_H
