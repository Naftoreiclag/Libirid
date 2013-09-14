#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>

/* Everything that has to do with grammar and the interpretation
 * of it.
 */

namespace gmr
{
    // Word types
    enum WordType
    {
        noun,
        adjunct,
        modifier,
        article,
        gibberish
    };

    // Articles
    enum ArticleType
    {
        definite, // the, that, this, those
        indefinite, // a, some
        erron,
    };

    //
    enum Plurality
    {
        singular,
        plural,
        ambiguo
    };

    //
    struct ArticleProperties
    {
        ArticleType type;
        Plurality quantity;
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

    // Adjunct pointer
    typedef unsigned int AdjunctId;

    // Noun vector
    struct NounState
    {
        NounId id;
        Plurality quantity;
        NounState(): id(0), quantity(ambiguo){}
        NounState(NounId id, Plurality quantity): id(id), quantity(quantity){}
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
    //typedef std::vector<PhraseType> SentenceStructure;

    // Sentences
    struct SentenceState
    {
        NounStateList nouns;
        bool hasPreposition;
        PrepositionState preposition;
    };
}

#endif // GRAMMAR_H
