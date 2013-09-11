#include "Dictionary.h"

#include <string>
#include <vector>

#include "WordNoun.h"
#include "Grammar.h"

std::vector<WordNoun*> Dictionary::registeredNouns;

NounId Dictionary::addNoun(WordNoun* newNoun)
{
    registeredNouns.push_back(newNoun);

    return registeredNouns.size() - 1;
}

std::size_t Dictionary::numNouns()
{
    return registeredNouns.size();
}

WordNoun* Dictionary::getNoun(NounId nounId)
{
    return registeredNouns.at(nounId);
}

Dictionary::Dictionary()
{
}
