#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <map>

#include "WordDefinitionNoun.h"
#include "WordDefinitionAdjunct.h"
#include "WordDefinitionModifier.h"
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
        static gmr::NounId addNoun(WordDefinitionNoun* newNoun);
        static WordDefinitionNoun* getNoun(gmr::NounId nounId);
        static std::size_t numNouns();

        // Adjuncts
        static gmr::AdjunctId addAdjunct(WordDefinitionAdjunct* newAdjunct);
        static WordDefinitionAdjunct* getAdjunct(gmr::AdjunctId adjunctId);
        static std::size_t numAdjuncts();

        // Modifiers
        static gmr::ModifierId addModifier(WordDefinitionModifier* newModifier);
        static WordDefinitionModifier* getModifier(gmr::ModifierId modifierId);
        static std::size_t numModifiers();

        // Articles
        static void addArticle(std::string name, gmr::ArticleType type, gmr::Plurality quantity);
        static gmr::ArticleProperties getArticle(std::string name);
        static std::size_t numArticles();
    private:
        // Nouns
        static std::vector<WordDefinitionNoun*> registeredNouns;

        // Adjuncts
        static std::vector<WordDefinitionAdjunct*> registeredAdjuncts;

        // Modifier
        static std::vector<WordDefinitionModifier*> registeredModifiers;

        // Articles
        static std::map<std::string, gmr::ArticleProperties> registeredArticles;

        // Private, because we'll never instantiate this.
        // Maybe someday we'll have separate dictionaries...?
        Dictionary();
};

#endif // DICTIONARY_H
