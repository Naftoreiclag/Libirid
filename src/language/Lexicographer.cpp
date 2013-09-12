#include "Lexicographer.h"

#include "Dictionary.h"
#include "Grammar.h"

#include "WordNoun.h"
#include "WordAdjunct.h"
#include "WordModifier.h"

#define D Dictionary

void Lexicographer::graph()
{
    D::addNoun(new WordNoun("cupcake"));
    D::addNoun(new WordNoun("bunny"));
    D::addNoun(new WordNoun("cookie"));
    D::addNoun(new WordNoun("potato"));
    D::addNoun(new WordNoun("sheep", "sheep"));
    D::addNoun(new WordNoun("couch"));

    D::addAdjunct(new WordAdjunct("above", gmr::above));
    D::addAdjunct(new WordAdjunct("below", gmr::below));
}

Lexicographer::Lexicographer()
{
}
