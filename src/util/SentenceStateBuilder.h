#ifndef SENTENCESTATEBUILDER_H
#define SENTENCESTATEBUILDER_H

#include <vector>

#include "../language/Grammar.h"

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
