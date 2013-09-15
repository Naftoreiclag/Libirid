#include "SentenceStateBuilder.h"

#include <vector>

#include "Grammar.h"
#include "Dictionary.h"

void SentenceStateBuilder::publishNoun()
{
    // Add the workspace address to the collection of addresses of completed nouns
    completedNouns->push_back(wipNoun);

    // Make a new workspace
    wipNoun = new gmr::NounState();
}

void SentenceStateBuilder::processNoun(gmr::NounId id, gmr::Plurality plurality)
{
    // If we can tell the difference between plural and singular
    if(!Dictionary::getNoun(id)->hasAmbiguousPlurality())
    {
        wipNoun->plurality = plurality;
    }

    // Set the id
    wipNoun->id = id;

    // Publish the noun
    publishNoun();
}

void SentenceStateBuilder::processArticle(gmr::ArticleProperties properties)
{
    // If we do not already know the plurality for the noun
    if(wipNoun->plurality == gmr::ambiguous)
    {
        // Set it to be this one
        wipNoun->plurality = properties.plurality;
    }

    // Set its definity
    wipNoun->definity = properties.type;
}

SentenceStateBuilder::SentenceStateBuilder()
{
    wipNoun = new gmr::NounState(); // The space we will build our work in progress (WIP) noun
    completedNouns = new std::vector<gmr::NounState*>(); // All of our completed nouns
}
