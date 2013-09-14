#include "Lexicographer.h"

#include "Dictionary.h"
#include "Grammar.h"

#include "NounDefinition.h"
#include "AdjunctDefinition.h"
#include "ModifierDefinition.h"

void Lexicographer::graph()
{
    // Na-Ooh-Nu-S
    Dictionary::addNoun(new NounDefinition("erroneous"));
    Dictionary::addNoun(new NounDefinition("fish", "fish"));
    Dictionary::addNoun(new NounDefinition("cupcake"));
    Dictionary::addNoun(new NounDefinition("bunny"));
    Dictionary::addNoun(new NounDefinition("egg"));
    Dictionary::addNoun(new NounDefinition("mouse", "mice"));
    Dictionary::addNoun(new NounDefinition("cookie"));
    Dictionary::addNoun(new NounDefinition("potato"));
    Dictionary::addNoun(new NounDefinition("sheep", "sheep"));
    Dictionary::addNoun(new NounDefinition("couch"));
    Dictionary::addNoun(new NounDefinition("sock"));
    Dictionary::addNoun(new NounDefinition("shoe"));
    Dictionary::addNoun(new NounDefinition("tomato"));

    // Adjuncts
    Dictionary::addAdjunct(new AdjunctDefinition("above", gmr::above));
    Dictionary::addAdjunct(new AdjunctDefinition("below", gmr::below));

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
