#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>

// Phrase types
enum PhraseType
{
    noun,
    adjunct
};

// Articles
enum ArticleType
{
    definite, // the, that, this, those
    indefinite, // a, some
    unspecified //
};

// Noun pointer
typedef unsigned int NounId;

// Modifier pointer
typedef unsigned int ModifierId;

//
typedef std::vector<ModifierId> ModifierList;

// Adjunct pointer
typedef unsigned int AdjunctId;

// Noun vector
struct NounState
{
    ArticleType article;
    ModifierList modifiers;
    NounId id;
};

//
struct PrepositionState
{
    AdjunctId adjunct;
    NounState prepositionalNoun;
};

//
typedef std::vector<NounState> NounStateList;

// Sentences
typedef std::vector<PhraseType> SentenceStructure;

// Sentences
struct SentenceState
{
    NounStateList nouns;
    bool hasPreposition;
    PrepositionState preposition;
};

class Grammar
{
    public:
    protected:
    private:
        Grammar() {}
};

#endif // GRAMMAR_H
