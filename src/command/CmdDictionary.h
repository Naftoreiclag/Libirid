#ifndef CMDDICTIONARY_H
#define CMDDICTIONARY_H

#include <string>

#include "../util/SequencedMap.h"

#include "Command.h"

class CmdDictionary
{
    public:
        // Note to self: Make this private and add the necessary get() and append()
        static SequencedMap<std::string, Command*>* cmdByAlias;
};

#endif // CMDDICTIONARY_H
