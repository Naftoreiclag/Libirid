#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>
#include "PhraseType.h"

// Sentences
typedef std::vector<PhraseType*> SentenceStructure;

// Part of speech
enum PartOfSpeech
{
    directObject,
    prepositionObject
};

class Grammar
{
    public:
    protected:
    private:
        Grammar() {}
};

#endif // GRAMMAR_H
