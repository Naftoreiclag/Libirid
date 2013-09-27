#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <vector>
#include <map>

#include "NounDefinition.h"
#include "AdjunctDefinition.h"
#include "ModifierDefinition.h"
#include "Grammar.h"

#ifdef DEBUG
#define private public
#endif

class string;

/* Pretty much just a dynamic lib for the different kinds
 * of words.
 */

class Dictionary
{
    public:
        // Identifying the word type
        //static gmr::WordType identifyWordType(std::string victim);

        // Getting noun state
        static gmr::NounState getNounState(std::string victim);
        //static gmr::AdjunctState getAdjunctState(std::string victim);

        /* ==== Nouns ==== */
        // Registry
        static void addNoun(gmr::NounId nounId, NounDefinition* newNoun);
        static NounDefinition* getNoun(gmr::NounId nounId);
        static gmr::NounId getNounId(std::string nounForm);
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
        // Number of
        static std::size_t numAdjuncts();

        /* ==== Modifiers ==== */
        // Registry
        static void addModifier(gmr::ModifierId modifierId, ModifierDefinition* newModifier);
        static ModifierDefinition* getModifier(gmr::ModifierId modifierId);
        static gmr::ModifierId getModifierId(std::string modifierForm);
        // Erroneous registry
        static void addModifierAsErroneous(gmr::ModifierId modifierId, ModifierDefinition* newModifier);
        static gmr::ModifierId getErroneousModifierId();

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
        static std::map<gmr::NounId, NounDefinition*> registeredNouns;
        static std::map<std::string, gmr::NounId> nounIdByForm;

        // Adjuncts
        static std::vector<AdjunctDefinition*> registeredAdjuncts;

        // Modifier
        static std::map<gmr::ModifierId, ModifierDefinition*> registeredModifiers;
        static std::map<std::string, gmr::ModifierId> modifierIdByForm;

        // Articles
        static std::map<std::string, gmr::ArticleProperties> registeredArticles;
};

#endif // DICTIONARY_H
