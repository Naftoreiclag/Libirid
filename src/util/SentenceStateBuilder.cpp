#include "SentenceStateBuilder.h"

#include <vector>

#include "Sysout.h"

#include "../language/Grammar.h"
#include "../language/Dictionary.h"

gmr::SentenceState* SentenceStateBuilder::processStatement(std::vector<std::string>* statement)
{
    // Make a new builder
    SentenceStateBuilder* ssbuilder = new SentenceStateBuilder();

    // Loop through all the words
    for(std::vector<std::string>::iterator wordPtr = statement->begin(); wordPtr != statement->end(); ++ wordPtr)
    {
    /* === Testing for nouns === */

        // Remembers if this word is a noun
        bool isNoun = false;

        // Test for nouns
        for(gmr::NounId possiblyMatchingNounId = 0; possiblyMatchingNounId < Dictionary::numNouns(); ++ possiblyMatchingNounId)
        {
            // Does it match the singular form?
            if(*wordPtr == Dictionary::getNoun(possiblyMatchingNounId)->getSingularForm())
            {
                // Process it
                ssbuilder->processNoun(possiblyMatchingNounId, gmr::singular);

                // It is a noun
                isNoun = true;

                // Do not test for the other nouns
                break;
            }

            // Does it match the plural form?
            else if(*wordPtr == Dictionary::getNoun(possiblyMatchingNounId)->getPluralForm())
            {
                // Process it
                ssbuilder->processNoun(possiblyMatchingNounId, gmr::plural);

                // It is a noun
                isNoun = true;

                // Do not test for the other nouns
                break;
            }
        }

        // If it is a noun, then obviously it can't be anything else,
        // So stop analyzing this word and look at the next word
        if(isNoun) { continue; }

    /* === Testing for articles === */

        // Test for articles
        gmr::ArticleProperties testArticleProperties = Dictionary::getArticle(*wordPtr);

        // If this article type is not erroneous
        if(testArticleProperties.type != gmr::undefinite)
        {
            ssbuilder->processArticle(testArticleProperties);

            // Continue to next word
            continue;
        }

    /* === Testing for modifiers === */

        // Remembers if this word is a noun
        bool isModifier = false;

        //
        gmr::ModifierId possiblyMatchingModifierId = Dictionary::getModifierId(*wordPtr);

        // Test for modifiers
        Sysout::println(possiblyMatchingModifierId);
        if(possiblyMatchingModifierId != Dictionary::getErroneousModifierId())
        {
            // Process it
        Sysout::println("notatnererr");
        Sysout::println(Dictionary::getModifier(possiblyMatchingModifierId)->getForm());
            ssbuilder->processModifier(possiblyMatchingModifierId);

            // It is a modifier
            isModifier = true;

            // Do not test for the other nouns
            break;
        }

        // If it is a noun, then obviously it can't be anything else,
        // So stop analyzing this word and look at the next word
        if(isModifier) { continue; }

    /* === Testing for adjuncts === */

        // Put something here
    }

    gmr::SentenceState* sntcState = ssbuilder->finish();

    delete ssbuilder;

    return sntcState;
}

gmr::SentenceState* SentenceStateBuilder::finish()
{
    return new gmr::SentenceState(completedNouns);
}

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

void SentenceStateBuilder::processModifier(gmr::ModifierId modifierId)
{
    bool alreadyHas = false;
    for(unsigned int indexOffset = 0; indexOffset < wipNoun->modifiers->size(); ++ indexOffset)
    {
        if(wipNoun->modifiers->at(indexOffset) == modifierId)
        {
            alreadyHas = true;
            break;
        }
    }


    if(!alreadyHas)
    {
        wipNoun->modifiers->push_back(modifierId);
    }
}

SentenceStateBuilder::SentenceStateBuilder()
{
    wipNoun = new gmr::NounState(); // The space we will build our work in progress (WIP) noun
    completedNouns = new std::vector<gmr::NounState*>(); // All of our completed nouns
}
