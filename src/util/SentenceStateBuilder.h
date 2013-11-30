/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef SENTENCESTATEBUILDER_H
#define SENTENCESTATEBUILDER_H

#include "../language/Grammar.h"

class vector;

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
