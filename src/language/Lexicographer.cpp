#include "Lexicographer.h"

#include "Dictionary.h"
#include "Grammar.h"

#include "WordNoun.h"
#include "WordAdjunct.h"
#include "WordModifier.h"

void Lexicographer::graph()
{
    Dictionary::addNoun(new WordNoun("cupcake"));
    Dictionary::addNoun(new WordNoun("bunny"));
    Dictionary::addNoun(new WordNoun("cookie"));
    Dictionary::addNoun(new WordNoun("potato"));
    Dictionary::addNoun(new WordNoun("sheep", "sheep"));
    Dictionary::addNoun(new WordNoun("couch"));

    Dictionary::addAdjunct(new WordAdjunct("above", gmr::above));
    Dictionary::addAdjunct(new WordAdjunct("below", gmr::below));

    Dictionary::addArticle("a", gmr::definite, gmr::solo);
    Dictionary::addArticle("some", gmr::definite, gmr::mas);
    Dictionary::addArticle("the", gmr::definite, gmr::solo);
}

Lexicographer::Lexicographer()
{
}
