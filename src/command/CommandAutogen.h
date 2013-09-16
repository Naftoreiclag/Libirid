#ifndef COMMANDAUTOGEN_H
#define COMMANDAUTOGEN_H

#include "Command.h"

#include "../language/Grammar.h"

class CommandAutogen: public Command
{
    public:
        bool execute(gmr::SentenceState* stnc);
        CommandAutogen();
    protected:
    private:
};

#endif // COMMANDAUTOGEN_H
