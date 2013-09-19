#ifndef CMDDICTIONARY_H
#define CMDDICTIONARY_H

#include <vector>
#include <string>

#include "../language/Grammar.h"

#include "../util/SequencedMap.h"

namespace fcmd
{
    typedef bool (*Functionality)(gmr::SentenceState* stnc, std::vector<std::string>* arguementWords, std::string alias);
}

class CmdDictionary
{
    public:
        // Note to self: Make this private and add the necessary get() and append()
        static SequencedMap<std::string, fcmd::Functionality>* cmdByAlias;
};

#endif // CMDDICTIONARY_H
