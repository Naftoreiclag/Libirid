#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <map>

#include "NounDefinition.h"
#include "AdjunctDefinition.h"
#include "ModifierDefinition.h"
#include "Grammar.h"

/* Pretty much just a dynamic lib for the different kinds
 * of words.
 */

class Dictionary
{
    public:
        // Identifying the word type
        static gmr::WordType identifyWordType(std::string victim);

        // Getting noun state
        static gmr::NounState getNounState(std::string victim);
        //static gmr::AdjunctState getAdjunctState(std::string victim);

        /* ==== Nouns ==== */
        // Registry
        static gmr::NounId addNoun(NounDefinition* newNoun);
        static NounDefinition* getNoun(gmr::NounId nounId);
        // Erroneous registry
        static gmr::NounId addNounAsErroneous(NounDefinition* newNoun);
        static gmr::NounId getErroneousNounId();
        // Number of
        static std::size_t numNouns();

        /* ==== Adjuncts ==== */
        // Registry
        static gmr::AdjunctId addAdjunct(AdjunctDefinition* newAdjunct);
        static AdjunctDefinition* getAdjunct(gmr::AdjunctId adjunctId);
        // Erroneous registry
        static gmr::AdjunctId addAdjunctAsErroneous(AdjunctDefinition* newAdjunct);
        static gmr::AdjunctId getErroneousAdjunctId();
        // Number of
        static std::size_t numAdjuncts();

        /* ==== Modifiers ==== */
        // Registry
        static gmr::ModifierId addModifier(ModifierDefinition* newModifier);
        static ModifierDefinition* getModifier(gmr::ModifierId modifierId);
        // Erroneous registry
        static gmr::ModifierId addModifierAsErroneous(ModifierDefinition* newModifier);
        static gmr::ModifierId getErroneousModifierId();
        // Number of
        static std::size_t numModifiers();

        /* ==== Articles ==== */
        static void addArticle(std::string name, gmr::ArticleType type, gmr::Plurality quantity);
        static gmr::ArticleProperties getArticle(std::string name);
        static std::size_t numArticles();

        static std::string getArticleForm(gmr::AdjunctType definity, gmr::Plurality plurality);
    private:
        //
        static gmr::NounId erroneousNounId;
        //
        static gmr::AdjunctId erroneousAdjunctId;
        //
        static gmr::ModifierId erroneousModifierId;

        // Nouns
        static std::vector<NounDefinition*> registeredNouns;

        // Adjuncts
        static std::vector<AdjunctDefinition*> registeredAdjuncts;

        // Modifier
        static std::vector<ModifierDefinition*> registeredModifiers;

        // Articles
        static std::map<std::string, gmr::ArticleProperties> registeredArticles;

        // Private, because we'll never instantiate this.
        // Maybe someday we'll have separate dictionaries...?
        Dictionary();
};

#endif // DICTIONARY_H
