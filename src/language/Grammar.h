#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>

//
enum PhraseType
{
    indirectObject,
    directObject,
    adjunctGenerical,
    adjunctAbove, // on, over, on top of
    adjunctTargetting, // to, at
    adjunctInside, // into
    prepositionalObject
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
