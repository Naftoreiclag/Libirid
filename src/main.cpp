#include <string>
#include <vector>
#include <map>

#include "util/SequencedMap.h"
#include "util/Sysout.h"
#include "util/Sysin.h"

#include "language/Grammar.h"
#include "language/Dictionary.h"
#include "language/Lexicographer.h"

#include "language/SentenceStateBuilder.h"

#include "command/Command.h"
#include "command/CommandEat.h"

#include "Oneint.h"

SequencedMap<std::string, Command*> cmdByAlias;

gmr::SentenceState* processStatement(std::vector<std::string>* statement)
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

        // Test for nouns
        for(gmr::ModifierId possiblyMatchingModifierId = 0; possiblyMatchingModifierId < Dictionary::numModifiers(); ++ possiblyMatchingModifierId)
        {
            // Does it match the singular form?
            if(*wordPtr == Dictionary::getModifier(possiblyMatchingModifierId)->getForm())
            {
                // Process it
                ssbuilder->processModifier(possiblyMatchingModifierId);

                // It is a noun
                isModifier = true;

                // Do not test for the other nouns
                break;
            }
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

bool alistatify(std::vector<std::string>* inputWords)
{
    // If we have no words
    if(inputWords->size() == 0)
    {
        // [Then obviously it cannot match anything]

        // Return unsuccessful
        return false;
    }

    // Loop through all commands
    for(unsigned int testCommandId = 0; testCommandId < cmdByAlias.size(); ++ testCommandId)
    {
        // Split the command's alias into a vector of individual words
        std::vector<std::string>* commandWords = new std::vector<std::string>();
        Sysin::splitWords(cmdByAlias.first(testCommandId), commandWords);

        // Check if we have enough input for it to be possible
        if(inputWords->size() < commandWords->size())
        {
            // [It cannot be this command]

            // Skip this one
            continue;
        }

        // Keeps track if the command comparison proves the input to start with the needed command
        bool commandMatches = true;

        // Get iterator for command words
        std::vector<std::string>::iterator commandWordFocus = commandWords->begin();

        // Iterate through the input words parallel
        std::vector<std::string>::iterator inputWordFocus = inputWords->begin();

        // Iterate through the command words
        while(commandWordFocus != commandWords->end())
        {
            // Check if this word is different
            if(*commandWordFocus != *inputWordFocus)
            {
                // [It is not]

                // The command therefore does not match
                commandMatches = false;

                // Stop checking, because it cannot possibly be it anymore
                break;
            }

            // Next
            ++ commandWordFocus;
            ++ inputWordFocus;
        }

        // If the command matches
        if(commandMatches)
        {
            // Get the command arguments
            std::vector<std::string>* arguementWords = new std::vector<std::string>(*inputWords);
            arguementWords->erase(arguementWords->begin(), arguementWords->begin() + commandWords->size());

            // Process them
            gmr::SentenceState* stncState = processStatement(arguementWords);

            // Delete them, since they are no longer needed.
            delete arguementWords;

            // Print stuff
            Sysout::print(Sysout::toFriendlyString(stncState));

            cmdByAlias.second(testCommandId)->execute(stncState);

            // Return successful
            return true;
        }

        // [The command did not match]

        // Delete our command word interpreter.
        delete commandWords;
    }

    // [None of the commands matched]

    // Return unsuccessful
    return false;
}

int main()
{
    /* === Testing === */

    // Put something here, k?

    /* === Actual program === */
    // Legend
    Sysout::println("Fuzzy Computing Machine");
    Sysout::println();

    // Add all the words
    Lexicographer::graph();

    // Print out the dictionary entries
    //Sysout::printDictionaryEntries();
    //Sysout::println();

    // Register commands
    cmdByAlias.append("eat", new CommandEat());

    // Running
    bool running = true;

    // Last input vector
    std::vector<std::string>* lastInput = new std::vector<std::string>();

    // While running, run!
    while(running)
    {
        // Prompt
        Sysout::println();
        Sysout::print("FCM:\\>"); Sysin::getWordsLowercase(lastInput);

        // Alistatify
        alistatify(lastInput);
    }

    // Delete our storage for the last container
    delete lastInput;

    // Died quietly
    return 0;
}
