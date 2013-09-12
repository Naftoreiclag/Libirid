#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <map>

#include "WordNoun.h"
#include "WordAdjunct.h"
#include "WordModifier.h"
#include "Grammar.h"

/* Pretty much just a dynamic lib for the different kinds
 * of words.
 */

class Dictionary
{
    public:
        // Nouns
        static gmr::NounId addNoun(WordNoun* newNoun);
        static WordNoun* getNoun(gmr::NounId nounId);
        static std::size_t numNouns();

        // Adjuncts
        static gmr::AdjunctId addAdjunct(WordAdjunct* newAdjunct);
        static WordAdjunct* getAdjunct(gmr::AdjunctId adjunctId);
        static std::size_t numAdjuncts();

        // Adjuncts
        static gmr::ModifierId addModifier(WordModifier* newModifier);
        static WordModifier* getModifier(gmr::ModifierId modifierId);
        static std::size_t numModifiers();

        // Articles
        static void addArticle(std::string name, gmr::ArticleType type, gmr::ArticleQuantity quantity);
        static gmr::ArticleProperties getArticle(std::string name);
    private:
        // Nouns
        static std::vector<WordNoun*> registeredNouns;

        // Adjuncts
        static std::vector<WordAdjunct*> registeredAdjuncts;

        // Modifier
        static std::vector<WordModifier*> registeredModifiers;

        // Articles
        static std::map<std::string, gmr::ArticleProperties> registeredArticles;

        // Private, because we'll never instantiate this.
        // Maybe someday we'll have separate dictionaries...?
        Dictionary();
};

#endif // DICTIONARY_H
