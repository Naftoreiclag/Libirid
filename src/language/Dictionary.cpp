#include "Dictionary.h"

#include <string>
#include <vector>

#include "NounWord.h"
#include "Grammar.h"

std::vector<NounWord*> Dictionary::registeredNouns;

NounId Dictionary::addNoun(NounWord* newNoun)
{
    registeredNouns.push_back(newNoun);

    return registeredNouns.size() - 1;
}

std::size_t Dictionary::numNouns()
{
    return registeredNouns.size();
}

NounWord* Dictionary::getNoun(NounId nounId)
{
    return registeredNouns.at(nounId);
}

Dictionary::Dictionary()
{
}
