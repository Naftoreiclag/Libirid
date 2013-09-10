#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>

//
enum PhraseType
{
    indirectNoun,
    directNoun,
    adjunctGenerical,
    adjunctAbove, // on, over, on top of
    adjunctTargetting, // to, at
    adjunctInside, // into
    prepositionalNoun
};

//
enum ArticleType
{
    definite, // the, that, this, those
    indefinite // a, some
};

// Sentences
typedef std::vector<PhraseType> SentenceStructure;

class Grammar
{
    public:
    protected:
    private:
        Grammar() {}
};

#endif // GRAMMAR_H
