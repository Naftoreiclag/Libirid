#ifndef COMMAND_H
#define COMMAND_H

#include "../language/Grammar.h"

class Command
{
    public:
        virtual bool execute(gmr::SentenceState* stnc);
    protected:
        Command();
};

#endif // COMMAND_H
