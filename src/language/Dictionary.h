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

        // Nouns
        static gmr::NounId addNoun(NounDefinition* newNoun);
        static gmr::NounId addNounAsErroneous(NounDefinition* newNoun);
        static NounDefinition* getNoun(gmr::NounId nounId);
        static gmr::NounId getErroneousNounId();
        static std::size_t numNouns();

        // Adjuncts
        static gmr::AdjunctId addAdjunct(AdjunctDefinition* newAdjunct);
        static gmr::AdjunctId addAdjunctAsErroneous(AdjunctDefinition* newAdjunct);
        static AdjunctDefinition* getAdjunct(gmr::AdjunctId adjunctId);
        static gmr::AdjunctId getErroneousAdjunctId();
        static std::size_t numAdjuncts();

        // Modifiers
        /*static gmr::ModifierId addModifier(ModifierDefinition* newModifier);
        static ModifierDefinition* getModifier(gmr::ModifierId modifierId);
        static std::size_t numModifiers();*/

        // Articles
        static void addArticle(std::string name, gmr::ArticleType type, gmr::Plurality quantity);
        static gmr::ArticleProperties getArticle(std::string name);
        static std::size_t numArticles();
    private:
        //
        static gmr::NounId erroneousNounId;
        //
        static gmr::AdjunctId erroneousAdjunctId;

        // Nouns
        static std::vector<NounDefinition*> registeredNouns;

        // Adjuncts
        static std::vector<AdjunctDefinition*> registeredAdjuncts;

        // Modifiergmr::NounId erroneousNounId;
        static std::vector<ModifierDefinition*> registeredModifiers;

        // Articles
        static std::map<std::string, gmr::ArticleProperties> registeredArticles;

        // Private, because we'll never instantiate this.
        // Maybe someday we'll have separate dictionaries...?
        Dictionary();
};

#endif // DICTIONARY_H
