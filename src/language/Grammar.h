#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>

/* Everything that has to do with grammar and the interpretation
 * of it.
 */

namespace gmr
{
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
        arroneous // erroneous
    };

    // Adjuncts
    enum AdjunctType
    {
        above,
        below
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
}

#endif // GRAMMAR_H
