#ifndef CMDDICTIONARY_H
#define CMDDICTIONARY_H

#include "../language/Grammar.h"

#include <vector>

class vector;
class string;

namespace fcmd
{
    typedef bool (*Functionality)(gmr::SentenceState* stnc, std::vector<std::string>* argumentWords, std::string alias);

    typedef std::pair<std::string, Functionality> AliasFunctionalityPair;
}

class CmdDictionary
{
    public:
        // Note to self: Make this private and add the necessary get() and append()
        static std::vector<fcmd::AliasFunctionalityPair>* cmdByAlias;
};

#endif // CMDDICTIONARY_H
