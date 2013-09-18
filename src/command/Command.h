#ifndef COMMAND_H
#define COMMAND_H

#include "../language/Grammar.h"
#include "../world/World.h"

class Command
{
    public:
        virtual bool execute(World* world, gmr::SentenceState* stnc);
    protected:
        Command();
};

#endif // COMMAND_H
