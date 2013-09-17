#ifndef CMDDICTIONARY_H
#define CMDDICTIONARY_H

#include <string>

#include "../util/SequencedMap.h"

#include "Command.h"

class CmdDictionary
{
    public:
        static SequencedMap<std::string, Command*>* cmdByAlias;
        CmdDictionary();
        virtual ~CmdDictionary();
    protected:
    private:
};

#endif // CMDDICTIONARY_H
