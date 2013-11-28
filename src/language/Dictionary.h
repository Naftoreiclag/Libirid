/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

// Data storage
#include <vector>
#include <map>

// Obviously, if we are dealing with the dictionaries, then we need the definitions
#include "NounDefinition.h"
#include "AdjunctDefinition.h"
#include "ModifierDefinition.h"

// Grammar types
#include "Grammar.h"

// If in debug mode, make everything public!
#ifdef DEBUG
#define private public
#endif

// Strings
class string;

/* Pretty much just a dynamic lib for the different kinds
 * of words.
 */

class Dictionary
{
    public:
        /* ==== Nouns ==== */
        // Registry
        static void addNoun(gmr::NounId nounId, NounDefinition* newNoun);
        static NounDefinition* getNoun(gmr::NounId nounId);
        static gmr::NounId getNounIdByPlural(std::string pluralNounForm);
        static gmr::NounId getNounIdBySingular(std::string singularNounForm);
        // Erroneous registry
        static void addNounAsErroneous(gmr::NounId nounId, NounDefinition* newNoun);
        static gmr::NounId getErroneousNounId();

        /* ==== Adjuncts ==== */
        // Registry
        static gmr::AdjunctId addAdjunct(AdjunctDefinition* newAdjunct);
        static AdjunctDefinition* getAdjunct(gmr::AdjunctId adjunctId);
        // Erroneous registry
        static gmr::AdjunctId addAdjunctAsErroneous(AdjunctDefinition* newAdjunct);
        static gmr::AdjunctId getErroneousAdjunctId();

        /* ==== Modifiers ==== */
        // Registry
        static void addModifier(gmr::ModifierId modifierId, ModifierDefinition* newModifier);
        static ModifierDefinition* getModifier(gmr::ModifierId modifierId);
        static gmr::ModifierId getModifierId(std::string modifierForm);
        // Erroneous registry
        static void addModifierAsErroneous(gmr::ModifierId modifierId, ModifierDefinition* newModifier);
        static gmr::ModifierId getErroneousModifierId();

        /* ==== Articles ==== */
        // Registry
        static void addArticle(std::string name, gmr::Definity type, gmr::Plurality quantity);
        static gmr::ArticleProperties getArticle(std::string name);

        static std::string getArticleForm(gmr::AdjunctType definity, gmr::Plurality plurality);
    private:
        // The erroneous return values if they can't be found
        static gmr::NounId erroneousNounId;
        static gmr::AdjunctId erroneousAdjunctId;
        static gmr::ModifierId erroneousModifierId;

        // Nouns
        static std::map<gmr::NounId, NounDefinition*> registeredNouns;
        static std::map<std::string, gmr::NounId> nounIdBySingularForm;
        static std::map<std::string, gmr::NounId> nounIdByPluralForm;

        // Adjuncts
        static std::vector<AdjunctDefinition*> registeredAdjuncts;

        // Modifier
        static std::map<gmr::ModifierId, ModifierDefinition*> registeredModifiers;
        static std::map<std::string, gmr::ModifierId> modifierIdByForm;

        // Articles
        static std::map<std::string, gmr::ArticleProperties> registeredArticles;
};

#endif // DICTIONARY_H
