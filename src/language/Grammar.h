#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>

// Phrase types
enum PhraseType
{
    noun,
    adjunctGenerical,
    adjunctAbove, // on, over, on top of
    adjunctTargetting, // to, at
    adjunctInside // into
};

// Articles
enum ArticleType
{
    definite, // the, that, this, those
    indefinite // a, some
};

//
typedef unsigned int NounId;

// Noun vector
struct NounState
{
    ArticleType article;
    NounId id;
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
