#ifndef COMMAND_H
#define COMMAND_H

#include <vector>

#include "language/Grammar.h"

class Command
{
    public:
        std::vector<SentenceStructure*> structures;
        Command();
    protected:
    private:
};

#endif // COMMAND_H
