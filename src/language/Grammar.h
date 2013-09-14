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
        ambiguous
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
    const NounId erroneousNounId = 0;

    // Adjunct pointer
    typedef unsigned int AdjunctId;

    // Noun
    class NounState
    {
        public:
            NounId id;
            Plurality plurality;
            NounState();
            NounState(NounId id, Plurality plurality);
    };

    //
    class SentenceState
    {
        public:
            bool has;
            NounState* prepositionalNoun;
            std::vector<NounState*>* nounStates;
            SentenceState(std::vector<NounState*>* nounStates);
    };
}

#endif // GRAMMAR_H
