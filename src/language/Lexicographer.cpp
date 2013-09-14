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
    Dictionary::addArticle("a", gmr::indefinite, singular);
    Dictionary::addArticle("an", gmr::indefinite, singular);
    Dictionary::addArticle("some", gmr::indefinite, plural);
    Dictionary::addArticle("the", gmr::definite, singular);
    Dictionary::addArticle("this", gmr::definite, singular);
    Dictionary::addArticle("that", gmr::definite, singular);
    Dictionary::addArticle("these", gmr::definite, plural);
    Dictionary::addArticle("those", gmr::definite, plural);
}

Lexicographer::Lexicographer()
{
}
