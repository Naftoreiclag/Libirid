#include "Dictionary.h"

#include <string>
#include <vector>
#include <map>

#include "NounDefinition.h"
#include "AdjunctDefinition.h"
#include "ModifierDefinition.h"
#include "Grammar.h"


// =====
// Nouns
// =====

// Vector
std::vector<NounDefinition*> Dictionary::registeredNouns;

//
gmr::NounId Dictionary::erroneousNounId;

// Add
gmr::NounId Dictionary::addNoun(NounDefinition* newNoun)
{
    registeredNouns.push_back(newNoun);

    return registeredNouns.size() - 1;
}

// Add
gmr::NounId Dictionary::addNounAsErroneous(NounDefinition* newNoun)
{
    registeredNouns.push_back(newNoun);

    erroneousNounId = registeredNouns.size() - 1;

    return registeredNouns.size() - 1;
}

// Get
NounDefinition* Dictionary::getNoun(gmr::NounId nounId)
{
    return registeredNouns.at(nounId);
}

gmr::NounId Dictionary::getErroneousNounId()
{
    return erroneousNounId;
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
std::vector<AdjunctDefinition*> Dictionary::registeredAdjuncts;
//
gmr::AdjunctId Dictionary::erroneousAdjunctId;

// Add
gmr::AdjunctId Dictionary::addAdjunct(AdjunctDefinition* newAdjunct)
{
    registeredAdjuncts.push_back(newAdjunct);

    return registeredAdjuncts.size() - 1;
}

// Add
gmr::AdjunctId Dictionary::addAdjunctAsErroneous(AdjunctDefinition* newAdjunct)
{
    registeredAdjuncts.push_back(newAdjunct);

    erroneousAdjunctId = registeredAdjuncts.size() - 1;

    return registeredAdjuncts.size() - 1;
}

// Get
AdjunctDefinition* Dictionary::getAdjunct(gmr::AdjunctId adjunctId)
{
    return registeredAdjuncts.at(adjunctId);
}

gmr::AdjunctId Dictionary::getErroneousAdjunctId()
{
    return erroneousAdjunctId;
}

// Number of
std::size_t Dictionary::numAdjuncts()
{
    return registeredAdjuncts.size();
}

// =========
// Modifiers
// =========

// Maps
std::map<gmr::ModifierId, ModifierDefinition*> Dictionary::registeredModifiers;
std::map<std::string, gmr::ModifierId> Dictionary::modifierIdByForm;
//
gmr::ModifierId Dictionary::erroneousModifierId;

// Add
void Dictionary::addModifier(gmr::ModifierId modifierId, ModifierDefinition* newModifier)
{
    registeredModifiers.insert(std::pair<gmr::ModifierId, ModifierDefinition*>(modifierId, newModifier));

    modifierIdByForm.insert(std::pair<std::string, gmr::ModifierId>(newModifier->getForm(), modifierId));
}

// Get
ModifierDefinition* Dictionary::getModifier(gmr::ModifierId modifierId)
{
    std::map<gmr::ModifierId, ModifierDefinition*>::iterator focus = registeredModifiers.find(modifierId);

    if(focus == registeredModifiers.end())
    {
        return registeredModifiers.find(erroneousModifierId)->second;
    }

    return focus->second;
}
gmr::ModifierId Dictionary::getModifierId(std::string modifierForm)
{
    std::map<std::string, gmr::ModifierId>::iterator focus = modifierIdByForm.find(modifierForm);

    if(focus == modifierIdByForm.end())
    {
        return erroneousModifierId;
    }

    return focus->second;
}

// Add Erroneous
void Dictionary::addModifierAsErroneous(gmr::ModifierId modifierId, ModifierDefinition* newModifier)
{
    registeredModifiers.insert(std::pair<gmr::ModifierId, ModifierDefinition*>(modifierId, newModifier));

    erroneousModifierId = modifierId;
}

// Get Erroneous
gmr::ModifierId Dictionary::getErroneousModifierId()
{
    return erroneousModifierId;
}

// Number of
/*
std::size_t Dictionary::numModifiers()
{
    return registeredModifiers.size();
}
*/

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
    a.plurality = mquantity;

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
        erroneous.type = gmr::undefinite;
        erroneous.plurality = gmr::ambiguous;
        return erroneous;
    }

    return focus->second;
}

// Number of
std::size_t Dictionary::numArticles()
{
    return registeredArticles.size();
}

std::string Dictionary::getArticleForm(gmr::AdjunctType definity, gmr::Plurality plurality)
{
    return "put something better here";
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
