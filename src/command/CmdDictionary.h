#ifndef CMDDICTIONARY_H
#define CMDDICTIONARY_H

#include "../language/Grammar.h"

#include "../util/SequencedMap.h"

class vector;
class string;

namespace fcmd
{
    typedef bool (*Functionality)(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias);
}

class CmdDictionary
{
    public:
        // Note to self: Make this private and add the necessary get() and append()
        static SequencedMap<std::string, fcmd::Functionality>* cmdByAlias;
};

#endif // CMDDICTIONARY_H
