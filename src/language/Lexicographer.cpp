#include "Lexicographer.h"

#include "Dictionary.h"
#include "Grammar.h"

#include "NounDefinition.h"
#include "AdjunctDefinition.h"
#include "ModifierDefinition.h"

void Lexicographer::graph()
{
    // Na-Ooh-Nu-S
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
    Dictionary::addNoun(new NounDefinition("dog"));
    Dictionary::addNoun(new NounDefinition("tree"));
    Dictionary::addNoun(new NounDefinition("grass"));
    Dictionary::addNoun(new NounDefinition("dirt"));
    Dictionary::addNoun(new NounDefinition("rock"));
    Dictionary::addNounAsErroneous(new NounDefinition("_HERPADERPDERP"));

    // Adjuncts
    Dictionary::addAdjunct(new AdjunctDefinition("above", gmr::above));
    Dictionary::addAdjunct(new AdjunctDefinition("below", gmr::below));
    Dictionary::addAdjunctAsErroneous(new AdjunctDefinition("_WITHURMOM", gmr::withurmom));

    // Modifiers
    Dictionary::addModifier(new ModifierDefinition("red"));
    Dictionary::addModifier(new ModifierDefinition("orange"));
    Dictionary::addModifier(new ModifierDefinition("yellow"));
    Dictionary::addModifier(new ModifierDefinition("green"));
    Dictionary::addModifier(new ModifierDefinition("blue"));
    Dictionary::addModifier(new ModifierDefinition("purple"));
    Dictionary::addModifier(new ModifierDefinition("magenta"));
    Dictionary::addModifier(new ModifierDefinition("funny"));
    Dictionary::addModifier(new ModifierDefinition("musical"));
    Dictionary::addModifier(new ModifierDefinition("brainy"));
    Dictionary::addModifier(new ModifierDefinition("rhythmic"));
    Dictionary::addModifier(new ModifierDefinition("undesirable"));
    Dictionary::addModifierAsErroneous(new ModifierDefinition("_ERRONEOUS"));

    // Meaningless modifiers
    Dictionary::addArticle("a", gmr::indefinite, gmr::singular);
    Dictionary::addArticle("an", gmr::indefinite, gmr::singular);
    Dictionary::addArticle("some", gmr::indefinite, gmr::plural);
    Dictionary::addArticle("the", gmr::definite, gmr::singular);
    Dictionary::addArticle("this", gmr::definite, gmr::singular);
    Dictionary::addArticle("that", gmr::definite, gmr::singular);
    Dictionary::addArticle("these", gmr::definite, gmr::plural);
    Dictionary::addArticle("those", gmr::definite, gmr::plural);
}
