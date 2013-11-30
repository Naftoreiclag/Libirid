/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Lexicographer.h"

#include "Dictionary.h"
#include "Grammar.h"

#include "NounDefinition.h"
#include "AdjunctDefinition.h"
#include "ModifierDefinition.h"

#include "../IdList.h"

void Lexicographer::graph()
{
    // Na-Ooh-Nu-S
    // ABCDEFGHIJKLMNOPQRSTUVWXYZ
    Dictionary::addNounAsErroneous(0, new NounDefinition("_HERPADERPDERP"));
    Dictionary::addNoun(    1, new NounDefinition("bunny"));
    Dictionary::addNoun(    2, new NounDefinition("cookie"));
    Dictionary::addNoun(    3, new NounDefinition("couch"));
    Dictionary::addNoun(   17, new NounDefinition("cupcake"));
    Dictionary::addNoun(    5, new NounDefinition("dirt"));
    Dictionary::addNoun(    6, new NounDefinition("dog"));
    Dictionary::addNoun(    7, new NounDefinition("egg"));
    Dictionary::addNoun(    8, new NounDefinition("fish", "fish"));
    Dictionary::addNoun(    9, new NounDefinition("grass"));
    Dictionary::addNoun(   10, new NounDefinition("leaf", "leaves"));
    Dictionary::addNoun(   11, new NounDefinition("mouse", "mice"));
    Dictionary::addNoun(   12, new NounDefinition("potato"));
    Dictionary::addNoun(   13, new NounDefinition("rock"));
    Dictionary::addNoun(   14, new NounDefinition("sheep", "sheep"));
    Dictionary::addNoun(   15, new NounDefinition("shoe"));
    Dictionary::addNoun(   16, new NounDefinition("sock"));
    Dictionary::addNoun(N_STICK, new NounDefinition("stick"));
    Dictionary::addNoun(   18, new NounDefinition("tomato"));
    Dictionary::addNoun(   19, new NounDefinition("tree"));

    // Adjuncts
    Dictionary::addAdjunct(new AdjunctDefinition("above", gmr::above));
    Dictionary::addAdjunct(new AdjunctDefinition("below", gmr::below));
    Dictionary::addAdjunctAsErroneous(new AdjunctDefinition("_WITHURMOM", gmr::withurmom));

    // Modifiers
    Dictionary::addModifierAsErroneous(0, new ModifierDefinition("_ERRONEOUS"));
    Dictionary::addModifier(    1, new ModifierDefinition("red"));
    Dictionary::addModifier(    2, new ModifierDefinition("orange"));
    Dictionary::addModifier(    3, new ModifierDefinition("yellow"));
    Dictionary::addModifier(    4, new ModifierDefinition("green"));
    Dictionary::addModifier(    5, new ModifierDefinition("blue"));
    Dictionary::addModifier(    6, new ModifierDefinition("purple"));
    Dictionary::addModifier(    7, new ModifierDefinition("magenta"));
    Dictionary::addModifier(    8, new ModifierDefinition("funny"));
    Dictionary::addModifier(    9, new ModifierDefinition("musical"));
    Dictionary::addModifier(   10, new ModifierDefinition("brainy"));
    Dictionary::addModifier(   11, new ModifierDefinition("rhythmic"));
    Dictionary::addModifier(   12, new ModifierDefinition("undesirable"));

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
