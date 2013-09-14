#include "Dictionary.h"

#include <string>
#include <vector>
#include <map>

#include "WordDefinitionNoun.h"
#include "WordDefinitionAdjunct.h"
#include "WordDefinitionModifier.h"
#include "Grammar.h"

// We will never instantiate you
Dictionary::Dictionary() {}

// =====
// Nouns
// =====

// Vector
std::vector<WordDefinitionNoun*> Dictionary::registeredNouns;

// Add
gmr::NounId Dictionary::addNoun(WordDefinitionNoun* newNoun)
{
    registeredNouns.push_back(newNoun);

    return registeredNouns.size() - 1;
}

// Get
WordDefinitionNoun* Dictionary::getNoun(gmr::NounId nounId)
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
std::vector<WordDefinitionAdjunct*> Dictionary::registeredAdjuncts;

// Add
gmr::AdjunctId Dictionary::addAdjunct(WordDefinitionAdjunct* newAdjunct)
{
    registeredAdjuncts.push_back(newAdjunct);

    return registeredAdjuncts.size() - 1;
}

// Get
WordDefinitionAdjunct* Dictionary::getAdjunct(gmr::AdjunctId adjunctId)
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
std::vector<WordDefinitionModifier*> Dictionary::registeredModifiers;

// Add
gmr::ModifierId Dictionary::addModifier(WordDefinitionModifier* newModifier)
{
    registeredModifiers.push_back(newModifier);

    return registeredModifiers.size() - 1;
}

// Get
WordDefinitionModifier* Dictionary::getModifier(gmr::ModifierId modifierId)
{
    return registeredModifiers.at(modifierId);
}

// Number of
std::size_t Dictionary::numModifiers()
{
    return registeredModifiers.size();
}

// ========
// Articles
// ========
// I'm different!

// Vector
std::map<std::string, gmr::ArticleProperties> Dictionary::registeredArticles;

// Add by name
void Dictionary::addArticle(std::string name, gmr::ArticleType mtype, gmr::Plurality mquantity)
{
    gmr::ArticleProperties a;
    a.type = mtype;
    a.quantity = mquantity;

    registeredArticles.insert(std::pair<std::string, gmr::ArticleProperties>(name, a));
}

// Get by name
gmr::ArticleProperties Dictionary::getArticle(std::string name)
{
    std::map<std::string, gmr::ArticleProperties>::iterator focus = registeredArticles.find(name);

    if(focus == registeredArticles.end())
    {
        // Returns a default value
        gmr::ArticleProperties erroneous;
        erroneous.type = gmr::indefinite;
        erroneous.quantity = gmr::ambiguo;
        return erroneous;
    }

    return focus->second;
}

// Number of
std::size_t Dictionary::numArticles()
{
    return registeredArticles.size();
}

// ==============
// Identification
// ==============

gmr::WordType Dictionary::identifyWordType(std::string victim)
{
    // Test for nouns
    for(gmr::NounId testNounId = 0; testNounId < numNouns(); ++ testNounId)
    {
        // Does it match the singular form?
        if(victim == registeredNouns.at(testNounId)->getSingularForm())
        {
            // It is a noun
            return gmr::noun;
        }

        // Does it match the plural form?
        if(victim == registeredNouns.at(testNounId)->getPluralForm())
        {
            // It is a noun
            return gmr::noun;
        }
    }

    // Test for adjuncts
    for(gmr::AdjunctId testAdjunctId = 0; testAdjunctId < numAdjuncts(); ++ testAdjunctId)
    {
        // Does it match?
        if(victim == registeredAdjuncts.at(testAdjunctId)->getForm())
        {
            // It is an adjunct
            return gmr::adjunct;
        }
    }

    // Test for articles
    std::map<std::string, gmr::ArticleProperties>::iterator testArticle = registeredArticles.find(victim);

    if(testArticle != registeredArticles.end())
    {
        return gmr::article;
    }

    // [None of the tests were successful]

    // It's gibberish
    return gmr::gibberish;
}
