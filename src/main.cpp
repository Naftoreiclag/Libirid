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

#include "Oneint.h"

SequencedMap<std::string, Command*> cmdByAlias;

void processStatement(std::vector<std::string>* statement)
{
    //
    SentenceStateBuilder* ssbuilder = new SentenceStateBuilder();

    for(std::vector<std::string>::iterator wordPtr = statement->begin(); wordPtr != statement->end(); ++ wordPtr)
    {
        Sysout::println(*wordPtr);
        Sysout::println("testing for nouns");

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
        Sysout::println("testing for articles");

        /* === Testing for articles === */

        // Test for articles
        gmr::ArticleProperties testArticleProperties = Dictionary::getArticle(*wordPtr);

        // If this article type is not erroneous
        Sysout::println(Sysout::toFriendlyString(testArticleProperties.type));
        if(testArticleProperties.type != gmr::undefinite)
        {
            ssbuilder->processArticle(testArticleProperties);

            // Continue to next word
            continue;
        }

        Sysout::println("testing for modifiers");
        /* === Testing for modifiers === */

        // Remembers if this word is a noun
        bool isModifier = false;

        // Test for nouns
        for(gmr::ModifierId possiblyMatchingModifierId = 0; possiblyMatchingModifierId < Dictionary::numModifiers(); ++ possiblyMatchingModifierId)
        {
            Sysout::println("trying " + Dictionary::getModifier(possiblyMatchingModifierId)->getForm());
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
    }

    // The return
    std::vector<gmr::NounState*> sentenceNounStateCollectionWorkshop(*(ssbuilder->completedNouns));

    delete ssbuilder;

    gmr::SentenceState sentenceState(&sentenceNounStateCollectionWorkshop);

    for(std::vector<gmr::NounState*>::iterator thisOneNoun = sentenceNounStateCollectionWorkshop.begin(); thisOneNoun != sentenceNounStateCollectionWorkshop.end(); ++ thisOneNoun)
    {
        Sysout::print(Sysout::toFriendlyString(*thisOneNoun));

        Sysout::print(" ");
    }
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
            processStatement(arguementWords);

            // Delete them, since they are no longer needed.
            delete arguementWords;

            /* Put something here! */

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

    // If I middle click, it auto pastes for me!

    /*Oneint* apple = new Oneint(1);
    Oneint* banana = apple;
    apple = new Oneint(2);
    Sysout::print(banana->getInt()); // I predict that it will print "1"*/
    // I was right!

    std::vector<Oneint*>* lotsoints = new std::vector<Oneint*>();

    Oneint* wipOneint = new Oneint(1);
    lotsoints->push_back(wipOneint);
    wipOneint = new Oneint(2);

    // I predict that it will print "1"

    Sysout::print(lotsoints->at(0)->getInt());
    //YAY!

    /* === Actual program === */
    // Legend
    Sysout::println("Fuzzy Computing Machine");
    Sysout::println();

    // Add all the words
    Lexicographer::graph();

    // Print out the dictionary entries
    Sysout::printDictionaryEntries();
    Sysout::println();

    // Register commands
    cmdByAlias.append("eat", new Command());

    // Running
    bool running = true;

    // Last input vector
    std::vector<std::string>* lastInput = new std::vector<std::string>();

    // While running, run!
    while(running)
    {
        Sysout::print("FCM:\\>"); Sysin::getWords(lastInput);
        Sysout::println();

        alistatify(lastInput);

        Sysout::println();
    }

    // Delete our storage for the last container
    delete lastInput;

    // Died quietly
    return 0;
}
