#include "Lexicographer.h"

#include "Dictionary.h"
#include "Grammar.h"

#include "WordDefinitionNoun.h"
#include "WordDefinitionAdjunct.h"
#include "WordDefinitionModifier.h"

void Lexicographer::graph()
{
    // Na-Ooh-Nu-S
    Dictionary::addNoun(new WordDefinitionNoun("erroneous"));
    Dictionary::addNoun(new WordDefinitionNoun("fish", "fish"));
    Dictionary::addNoun(new WordDefinitionNoun("cupcake"));
    Dictionary::addNoun(new WordDefinitionNoun("bunny"));
    Dictionary::addNoun(new WordDefinitionNoun("egg"));
    Dictionary::addNoun(new WordDefinitionNoun("mouse", "mice"));
    Dictionary::addNoun(new WordDefinitionNoun("cookie"));
    Dictionary::addNoun(new WordDefinitionNoun("potato"));
    Dictionary::addNoun(new WordDefinitionNoun("sheep", "sheep"));
    Dictionary::addNoun(new WordDefinitionNoun("couch"));
    Dictionary::addNoun(new WordDefinitionNoun("sock"));
    Dictionary::addNoun(new WordDefinitionNoun("shoe"));
    Dictionary::addNoun(new WordDefinitionNoun("tomato"));

    // Adjuncts
    Dictionary::addAdjunct(new WordDefinitionAdjunct("above", gmr::above));
    Dictionary::addAdjunct(new WordDefinitionAdjunct("below", gmr::below));

    // Meaningless modifiers
    Dictionary::addArticle("a", gmr::indefinite, gmr::solo);
    Dictionary::addArticle("an", gmr::indefinite, gmr::solo);
    Dictionary::addArticle("some", gmr::indefinite, gmr::muchos);
    Dictionary::addArticle("the", gmr::definite, gmr::solo);
    Dictionary::addArticle("this", gmr::definite, gmr::solo);
    Dictionary::addArticle("that", gmr::definite, gmr::solo);
    Dictionary::addArticle("these", gmr::definite, gmr::muchos);
    Dictionary::addArticle("those", gmr::definite, gmr::muchos);
}

Lexicographer::Lexicographer()
{
}
