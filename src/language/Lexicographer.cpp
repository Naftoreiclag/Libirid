#include "Lexicographer.h"

#include "Dictionary.h"
#include "WordNoun.h"
#include "WordAdjunct.h"
#include "WordModifier.h"

void Lexicographer::graph()
{
    Dictionary::addNoun(new WordNoun("bunny"));
    Dictionary::addNoun(new WordNoun("cookie"));
    Dictionary::addNoun(new WordNoun("potato"));
}

Lexicographer::Lexicographer()
{
}
