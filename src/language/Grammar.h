#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <vector>
#include <string>

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
    enum Definity
    {
        definite, // the, that, this, those
        indefinite, // a, some
        undefinite // only used for the erroneous return
    };

    //
    enum Plurality
    {
        singular, // One
        plural, // Two or more
        ambiguous // Cannot be locally determined (e.g. sheep or fish)
    };

    // Adjuncts
    enum AdjunctType
    {
        above,
        below,
        withurmom
    };

    //
    struct ArticleProperties
    {
        Definity type;
        Plurality plurality;
    };

    // Noun pointer
    typedef unsigned int NounId;

    // Adjunct pointer
    typedef unsigned int AdjunctId;

    // Modifier pointer
    typedef unsigned int ModifierId;

    // Noun
    class NounState
    {
        public:
            NounId id;
            Plurality plurality;
            Definity definity;
            std::vector<gmr::ModifierId>* modifiers;

            std::string getModifiedName();
            std::string getUnmodifiedName();

            NounState();
    };

    // Modifier
    class ModifierState
    {
        public:
            ModifierId id;
            ModifierState();
            ModifierState(ModifierId id);
    };

    //
    class SentenceState
    {
        public:
            std::vector<NounState*>* nounStates;
            SentenceState(std::vector<NounState*>* nounStates);
    };
}

#endif // GRAMMAR_H
