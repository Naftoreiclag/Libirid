#ifndef SENTENCESTATEBUILDER_H
#define SENTENCESTATEBUILDER_H

#include <vector>

#include "Grammar.h"

// I think this should be moved to util (virtual folder?)

class SentenceStateBuilder
{
    public:
        static gmr::SentenceState* processStatement(std::vector<std::string>* statement);

        gmr::SentenceState* finish();
        std::vector<gmr::NounState*>* completedNouns;
        void processNoun(gmr::NounId id, gmr::Plurality plurality);
        void processArticle(gmr::ArticleProperties properties);
        void processModifier(gmr::ModifierId modifierId);
        SentenceStateBuilder();
    protected:
    private:
        void publishNoun();
        gmr::NounState* wipNoun;
};

#endif // SENTENCESTATEBUILDER_H
