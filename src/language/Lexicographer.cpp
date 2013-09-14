#include "Lexicographer.h"

#include "Dictionary.h"
#include "Grammar.h"

#include "NounDefinition.h"
#include "AdjunctDefinition.h"
#include "ModifierDefinition.h"

void Lexicographer::graph()
{
    // Nouns
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
    Dictionary::addNounAsErroneous(new NounDefinition("ERROR"));

    // Adjuncts
    Dictionary::addAdjunct(new AdjunctDefinition("above", gmr::above));
    Dictionary::addAdjunct(new AdjunctDefinition("below", gmr::below));

    // Modifiers
    Dictionary::addModifier(new ModifierDefinition("blue"));
    Dictionary::addModifier(new ModifierDefinition("red"));
    Dictionary::addModifier(new ModifierDefinition("green"));
    Dictionary::addModifierAsErroneous(new ModifierDefinition("ERRONEOUS"));

    // Articles
    Dictionary::addArticle("a", gmr::indefinite, gmr::singular);
    Dictionary::addArticle("an", gmr::indefinite, gmr::singular);
    Dictionary::addArticle("some", gmr::indefinite, gmr::plural);
    Dictionary::addArticle("the", gmr::definite, gmr::singular);
    Dictionary::addArticle("this", gmr::definite, gmr::singular);
    Dictionary::addArticle("that", gmr::definite, gmr::singular);
    Dictionary::addArticle("these", gmr::definite, gmr::plural);
    Dictionary::addArticle("those", gmr::definite, gmr::plural);
}

Lexicographer::Lexicographer()
{
}
