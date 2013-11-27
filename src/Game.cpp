#include "Game.h"

#include "util/Sysout.h"
#include "util/Sysin.h"
#include "util/SentenceStateBuilder.h"

#include "command/CmdDictionary.h"

#include "language/Grammar.h"

#include "world/World.h"
#include "world/Player.h"

Game::Game()
: running(false)
{
}

void Game::run()
{
    // We are running now
    running = true;

    // Last input vector
    std::vector<std::string>* lastInput = new std::vector<std::string>();

    //
    //world = new World();

    //
    //player = new Player(world->getRoom(Point3i(5, 5, 5)));

    // While running, run!
    while(running)
    {
        // Prompt
        Sysout::print("FCM:\\>"); Sysin::getWordsLowercase(lastInput);
        Sysout::println();
        /*)

        // Run command from the raw input
        bool success = runCommandFromRawInput(lastInput);
        if(!success)
        {
            // Inform
            #ifdef DEBUG
            Sysout::print("Could not understand input: ");
            Sysout::println(Sysout::toFriendlyString(lastInput));
            #endif // DEBUG
            Sysout::println("Misunderstanding.");
            Sysout::println();
        }*/
    }

    // Delete our storage for the last container
    delete lastInput;

    // Maybe now would be a good time to save?
    delete world;
}
/*
bool Game::runCommandFromSudoInput(std::string sudoLine)
{
    std::vector<std::string>* inputWords = new std::vector<std::string>();
    Sysin::splitWords(sudoLine, inputWords);

    bool success = runCommandFromRawInput(inputWords);

    delete inputWords;

    return success;
}

bool Game::runCommandFromRawInput(std::vector<std::string>* inputWords)
{
    #ifdef DEBUG_FINE
    Sysout::println("-BEGIN INPUT PROCESSING");
    Sysout::print("-Processing: ");
    Sysout::println(Sysout::toFriendlyString(inputWords));
    #endif // DEBUG_FINE

    // If we have no words
    if(inputWords->size() == 0)
    {
        // [Then obviously it cannot match anything]

        // Return unsuccessful
        return false;
    }

    // Loop through all commands
    for(unsigned int testCommandId = 0; testCommandId < CmdDictionary::cmdByAlias->size(); ++ testCommandId)
    {
        // Split the command's alias into a vector of individual words
        std::vector<std::string>* commandWords = new std::vector<std::string>();
        Sysin::splitWords(CmdDictionary::cmdByAlias->at(testCommandId).first, commandWords);

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
            // Debug
            #ifdef DEBUG_FINE
            Sysout::println("--BEGIN COMMAND PROCESSING");
            Sysout::print("--Command: ");
            Sysout::println(CmdDictionary::cmdByAlias->at(testCommandId).first);
            #endif // DEBUG_FINE

            // Get the command arguments
            std::vector<std::string>* argumentWords = new std::vector<std::string>(*inputWords);
            argumentWords->erase(argumentWords->begin(), argumentWords->begin() + commandWords->size());

            // Process them
            gmr::SentenceState* stncState = SentenceStateBuilder::processStatement(argumentWords);

            // Print debug stuff
            #ifdef DEBUG_FINE
            Sysout::print("--Syntax: ");
            Sysout::println(Sysout::toFriendlyString(stncState));
            #endif // DEBUG_FINE

            // Run the command       [-----------Function Pointer----------------------][-----------------------Function Parameters----------------------------------]
            bool commandSuccessful = CmdDictionary::cmdByAlias->at(testCommandId).second(stncState, argumentWords, CmdDictionary::cmdByAlias->at(testCommandId).first);

            // Delete them, since they are no longer needed.
            delete argumentWords;
            delete stncState;

            // If it was successful
            if(commandSuccessful)
            {
                // Debug
                #ifdef DEBUG_FINE
                Sysout::println("--Command successful.");
                Sysout::println("--END COMMAND PROCESSING");
                Sysout::println("-END INPUT PROCESSING");
                #endif // DEBUG_FINE

                // Return successful
                return true;
            }

            // [The command was not successful]

            // Debug
            #ifdef DEBUG_FINE
            Sysout::println("--Command failed.");
            Sysout::println("--END COMMAND PROCESSING");
            #endif // DEBUG_FINE
        }

        // [The command did not match]

        // Delete our command word interpreter.
        delete commandWords;
    }

    // [None of the commands matched]

    // Debug
    #ifdef DEBUG_FINE
    Sysout::println("-END INPUT PROCESSING");
    #endif // DEBUG_FINE

    // Return unsuccessful
    return false;
}
*/
