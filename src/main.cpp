#include <string>
#include <vector>
#include <map>

#include "util/SequencedMap.h"
#include "util/Sysout.h"
#include "util/Sysin.h"

#include "language/Grammar.h"
#include "language/Dictionary.h"
#include "language/Lexicographer.h"

#include "command/Command.h"

SequencedMap<std::string, Command*> cmdByAlias;

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
        // Info
        Sysout::print(" Testing for ");
        Sysout::println(cmdByAlias.first(testCommandId));

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

            // The return
            std::vector<gmr::NounState*> sentenceNounStateCollectionWorkshop;

            // Storage for nouns
            gmr::NounState* nounStateWorkshop = new gmr::NounState();

            for(std::vector<std::string>::iterator argFocus = arguementWords->begin(); argFocus != arguementWords->end(); ++ argFocus)
            {
                // Test for nouns
                for(gmr::NounId testNounId = 0; testNounId < Dictionary::numNouns(); ++ testNounId)
                {
                    // Does it match the singular form?
                    if(*argFocus == Dictionary::getNoun(testNounId)->getSingularForm())
                    {
                        // It must be this id then
                        nounStateWorkshop->id = testNounId;

                        if(!Dictionary::getNoun(testNounId)->hasAmbiguousPlurality())
                        {
                            // It must be singular
                            nounStateWorkshop->plurality = gmr::singular;
                        }

                        // [At this point, the NounState must be complete, so let's finalize it and prepare a new workshop.]

                        // Clone over all the values
                        gmr::NounState pushMe(nounStateWorkshop->id, nounStateWorkshop->plurality);
                        sentenceNounStateCollectionWorkshop.push_back(&pushMe);

                        // Clear out the workshop
                        nounStateWorkshop = new gmr::NounState();

                        // Continue to next word
                        continue;
                    }

                    // Does it match the plural form?
                    if(*argFocus == Dictionary::getNoun(testNounId)->getPluralForm())
                    {
                        // It must be this id then
                        nounStateWorkshop->id = testNounId;

                        if(!Dictionary::getNoun(testNounId)->hasAmbiguousPlurality())
                        {
                            // It must be singular
                            nounStateWorkshop->plurality = gmr::plural;
                        }

                        // [At this point, the NounState must be complete, so let's finalize it and prepare a new workshop.]

                        // Clone over all the values
                        gmr::NounState pushMe(nounStateWorkshop->id, nounStateWorkshop->plurality);
                        sentenceNounStateCollectionWorkshop.push_back(&pushMe);

                        // Clear out the workshop
                        nounStateWorkshop = new gmr::NounState();

                        // Continue to next word
                        continue;
                    }
                }

                // Test for articles
                gmr::ArticleProperties testArticleProperties = Dictionary::getArticle(*argFocus);

                if(testArticleProperties.type != gmr::erron)
                {
                    if(nounStateWorkshop->plurality == gmr::ambiguous)
                    {
                        nounStateWorkshop->plurality = testArticleProperties.quantity;
                    }

                    // Continue to next word
                    continue;
                }
            }

            gmr::SentenceState sentenceState(stnc);

            Sysout::println();
            Sysout::println();
            for(std::vector<gmr::NounState*>::iterator thisOneNoun = sentenceNounStateCollectionWorkshop.begin(); thisOneNoun != sentenceNounStateCollectionWorkshop.end(); ++ thisOneNoun)
            {
                Sysout::print("[");
                Sysout::print(Dictionary::getNoun((*thisOneNoun)->id)->getSingularForm());
                Sysout::print("-");
                Sysout::print(Sysout::toFriendlyString((*thisOneNoun)->plurality));
                Sysout::print("]");

                Sysout::print(" ");
            }

            // <Get the argument sentence structure>


            // <Loop through that command's sentence structures to see if they fit.>
            //

            // Delete the argument container
            delete arguementWords;

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
    // Legend
    Sysout::println("Fuzzy Computing Machine");
    Sysout::println();

    Lexicographer::graph();

    Sysout::printDictionaryEntries();
    Sysout::println();

    // Register commands
    cmdByAlias.append("eat", new Command());
    cmdByAlias.append("chow down", new Command());
    cmdByAlias.append("take a dump", new Command());
    cmdByAlias.append("dance", new Command());
    cmdByAlias.append("take", new Command());

    // Running
    bool running = true;

    // Last input vector
    std::vector<std::string>* lastInput = new std::vector<std::string>();

    // While running, run!
    while(running)
    {
        Sysout::println("Enter something:");

        Sysout::print("FCM:\\>");
        Sysin::getWords(lastInput);
        Sysout::println();

        // Example of how to make vector clones
        std::vector<std::string> vc(*lastInput);
        Sysout::print("The copy of the vector is: ");
        Sysout::println(&vc);
        Sysout::println();

        // This is going to crash the program since there's no check to see if lastInput has anything. But who cares!?
        Sysout::print("The first word is a: ");
        Sysout::print(Sysout::toFriendlyString(Dictionary::identifyWordType(lastInput->at(0))));
        Sysout::println();
        Sysout::println();

        Sysout::print("You entered:");
        Sysout::println(lastInput);

        Sysout::println("Trying to recognize command...");

        alistatify(lastInput);

        Sysout::println();
    }

    delete lastInput;

    // Died quietly
    return 0;
}
