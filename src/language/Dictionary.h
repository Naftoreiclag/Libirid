#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>

#include "NounWord.h"
#include "Grammar.h"

class Dictionary
{
    public:
        static NounWord* getNoun(NounId nounId);
        static std::size_t numNouns();
        static NounId addNoun(NounWord* newNoun);
    protected:
    private:
        static std::vector<NounWord*> registeredNouns;
        Dictionary();
};

#endif // DICTIONARY_H
