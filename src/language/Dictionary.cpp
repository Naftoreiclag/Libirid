#include "Dictionary.h"

#include <string>
#include <vector>

#include "WordNoun.h"
#include "Grammar.h"

// We will never instantiate you
Dictionary::Dictionary() {}

// =====
// Nouns
// =====

// Vector
std::vector<WordNoun*> Dictionary::registeredNouns;

// Add
NounId Dictionary::addNoun(WordNoun* newNoun)
{
    registeredNouns.push_back(newNoun);

    return registeredNouns.size() - 1;
}

// Get
WordNoun* Dictionary::getNoun(NounId nounId)
{
    return registeredNouns.at(nounId);
}

// Number of
std::size_t Dictionary::numNouns()
{
    return registeredNouns.size();
}

// ========
// Adjuncts
// ========

// Vector
std::vector<WordAdjunct*> Dictionary::registeredAdjuncts;

// Add
AdjunctId Dictionary::addAdjunct(WordAdjunct* newAdjunct)
{
    registeredAdjuncts.push_back(newAdjunct);

    return registeredAdjuncts.size() - 1;
}

// Get
WordAdjunct* Dictionary::getAdjunct(AdjunctId adjunctId)
{
    return registeredAdjuncts.at(adjunctId);
}

// Number of
std::size_t Dictionary::numAdjuncts()
{
    return registeredAdjuncts.size();
}

// =========
// Modifiers
// =========

// Vector
std::vector<WordModifier*> Dictionary::registeredModifiers;

// Add
ModifierId Dictionary::addModifier(WordModifier* newModifier)
{
    registeredModifiers.push_back(newModifier);

    return registeredModifiers.size() - 1;
}

// Get
WordModifier* Dictionary::getModifier(ModifierId modifierId)
{
    return registeredModifiers.at(modifierId);
}

// Number of
std::size_t Dictionary::numModifiers()
{
    return registeredModifiers.size();
}
