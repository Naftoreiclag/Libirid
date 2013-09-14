#include "SentenceStateBuilder.h"

#include <vector>

#include "Grammar.h"

void SentenceStateBuilder::publishNoun()
{
    // Make a copy of what we got in the workspace
    gmr::NounState* nounProduct = new gmr::NounState();
    nounProduct->id = wipNoun->id; // Same id
    nounProduct->plurality = wipNoun->plurality; // Same plurality
}

void SentenceStateBuilder::processNoun(gmr::NounId id, gmr::Plurality plurality)
{

}

SentenceStateBuilder::SentenceStateBuilder()
{
    wipNoun = new gmr::NounState(); // The space we will build our work in progress (WIP) noun
    completedNouns = new std::vector<gmr::NounState*>(); // All of our completed nouns
}
