#include "Dictionary.h"

#include <string>
#include <vector>
#include <map>

#include "NounDefinition.h"
#include "AdjunctDefinition.h"
#include "ModifierDefinition.h"
#include "Grammar.h"

#ifdef DEBUG
#include "../util/Sysout.h"
#endif // DEBUG


// =====
// Nouns
// =====

// Vector
std::map<gmr::NounId, NounDefinition*> Dictionary::registeredNouns;
std::map<std::string, gmr::NounId> Dictionary::nounIdBySingularForm;
std::map<std::string, gmr::NounId> Dictionary::nounIdByPluralForm;

//
gmr::NounId Dictionary::erroneousNounId;

// Add
void Dictionary::addNoun(gmr::NounId nounId, NounDefinition* newNoun)
{
    #ifdef DEBUG
    std::map<gmr::NounId, NounDefinition*>::iterator focus = registeredNouns.find(nounId);

    if(focus != registeredNouns.end())
    {
        Sysout::print("[Warning] You are trying to add two nouns with the same id! ");
        Sysout::println(Sysout::toString(nounId));
    }
    #endif // DEBUG

    registeredNouns.insert(std::pair<gmr::NounId, NounDefinition*>(nounId, newNoun));

    nounIdBySingularForm.insert(std::pair<std::string, gmr::NounId>(newNoun->getSingularForm(), nounId));
    nounIdByPluralForm.insert(std::pair<std::string, gmr::NounId>(newNoun->getPluralForm(), nounId));
}

// Get
NounDefinition* Dictionary::getNoun(gmr::NounId nounId)
{
    std::map<gmr::NounId, NounDefinition*>::iterator focus = registeredNouns.find(nounId);

    if(focus == registeredNouns.end())
    {
        return registeredNouns.find(erroneousModifierId)->second;
    }

    return focus->second;
}

// Get Id
gmr::NounId Dictionary::getNounIdBySingular(std::string singularNounForm)
{
    std::map<std::string, gmr::NounId>::iterator focus = nounIdBySingularForm.find(singularNounForm);

    if(focus == nounIdBySingularForm.end())
    {
        return erroneousNounId;
    }

    return focus->second;
}
gmr::NounId Dictionary::getNounIdByPlural(std::string pluralNounForm)
{
    std::map<std::string, gmr::NounId>::iterator focus = nounIdByPluralForm.find(pluralNounForm);

    if(focus == nounIdByPluralForm.end())
    {
        return erroneousNounId;
    }

    return focus->second;
}

// Add
void Dictionary::addNounAsErroneous(gmr::NounId nounId, NounDefinition* newNoun)
{
    registeredNouns.insert(std::pair<gmr::NounId, NounDefinition*>(nounId, newNoun));

    erroneousNounId = nounId;
}

gmr::NounId Dictionary::getErroneousNounId()
{
    return erroneousNounId;
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

// Get Id
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

// ========
// Articles
// ========
// I'm different!

// Vector
std::map<std::string, gmr::ArticleProperties> Dictionary::registeredArticles;

// Add by name
void Dictionary::addArticle(std::string name, gmr::Definity mtype, gmr::Plurality mquantity)
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

std::string Dictionary::getArticleForm(gmr::AdjunctType definity, gmr::Plurality plurality)
{
    return "put something better here";
}
