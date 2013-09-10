#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>
#include "PhraseType.h"

// Sentences
typedef std::vector<PhraseType*> SentenceStructure;

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

class Grammar
{
    public:
    protected:
    private:
        Grammar() {}
};

#endif // GRAMMAR_H
