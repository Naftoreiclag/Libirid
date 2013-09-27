#include "SentenceStateBuilder.h"

#include <vector>

#include "../language/Grammar.h"
#include "../language/Dictionary.h"

// Process a vector of strings
gmr::SentenceState* SentenceStateBuilder::processStatement(std::vector<std::string>* statement)
{
    // Make a new builder
    SentenceStateBuilder* ssbuilder = new SentenceStateBuilder();

    // Loop through all the words
    for(std::vector<std::string>::iterator wordPtr = statement->begin(); wordPtr != statement->end(); ++ wordPtr)
    {
    /* === Testing for nouns === */

        // Test for nouns
        gmr::NounId possiblyMatchingNounId = Dictionary::getNounId(*wordPtr);

        // If this noun is not erroneous
        if(possiblyMatchingNounId != Dictionary::getErroneousNounId())
        {
            // Process it
            ssbuilder->processNoun(possiblyMatchingNounId, gmr::singular);

            // If it is a noun, then obviously it can't be anything else,
            // So stop analyzing this word and look at the next word
            continue;
        }

    /* === Testing for articles === */

        // Test for articles
        gmr::ArticleProperties testArticleProperties = Dictionary::getArticle(*wordPtr);

        // If this article type is not erroneous
        if(testArticleProperties.type != gmr::undefinite)
        {
            // Process it
            ssbuilder->processArticle(testArticleProperties);

            // Continue to next word
            continue;
        }

    /* === Testing for modifiers === */

        // Test for modifiers
        gmr::ModifierId possiblyMatchingModifierId = Dictionary::getModifierId(*wordPtr);

        // If this modifier is not erroneous
        if(possiblyMatchingModifierId != Dictionary::getErroneousModifierId())
        {
            // Process it
            ssbuilder->processModifier(possiblyMatchingModifierId);

            // If it is a modifier, then obviously it can't be anything else,
            // So stop analyzing this word and look at the next word
            continue;
        }

    /* === Testing for adjuncts === */

        // Put something here
    }

    gmr::SentenceState* sntcState = ssbuilder->finish();

    delete ssbuilder;

    return sntcState;
}

// Finalize stuff
gmr::SentenceState* SentenceStateBuilder::finish()
{
    return new gmr::SentenceState(completedNouns);
}

// Finalize noun and add it to the list of completed nouns
void SentenceStateBuilder::publishNoun()
{
    // Add the workspace address to the collection of addresses of completed nouns
    completedNouns->push_back(wipNoun);

    // Make a new workspace
    wipNoun = new gmr::NounState();
}

// Process a noun
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

// Process an article
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

// Process a modifier
void SentenceStateBuilder::processModifier(gmr::ModifierId modifierId)
{
    // Remembers if we already have that modifier
    bool alreadyHas = false;

    // Iterate through all the modifiers
    for(unsigned int indexOffset = 0; indexOffset < wipNoun->modifiers->size(); ++ indexOffset)
    {
        // If that modifier is the same
        if(wipNoun->modifiers->at(indexOffset) == modifierId)
        {
            // Then remember
            alreadyHas = true;

            // Stop checking
            break;
        }
    }

    // If we do not already have it
    if(!alreadyHas)
    {
        // Add it
        wipNoun->modifiers->push_back(modifierId);
    }
}

// Constructor
SentenceStateBuilder::SentenceStateBuilder()
{
    wipNoun = new gmr::NounState(); // The space we will build our work in progress (WIP) noun
    completedNouns = new std::vector<gmr::NounState*>(); // All of our completed nouns
}
