#ifndef SENTENCESTATEBUILDER_H
#define SENTENCESTATEBUILDER_H

#include <vector>

#include "Grammar.h"

// I think this should be moved to util (virtual folder?)

class SentenceStateBuilder
{
    public:
        void processNoun(gmr::NounId id, gmr::Plurality plurality);
        void processArticle(gmr::ArticleProperties properties);
        SentenceStateBuilder();
    protected:
    private:
        void publishNoun();
        gmr::NounState* wipNoun;
        std::vector<gmr::NounState*>* completedNouns;
};

#endif // SENTENCESTATEBUILDER_H
