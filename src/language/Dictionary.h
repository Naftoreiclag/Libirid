#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>

#include "WordNoun.h"
#include "Grammar.h"

class Dictionary
{
    public:
        static WordNoun* getNoun(NounId nounId);
        static std::size_t numNouns();
        static NounId addNoun(WordNoun* newNoun);
    protected:
    private:
        static std::vector<WordNoun*> registeredNouns;
        Dictionary();
};

#endif // DICTIONARY_H
