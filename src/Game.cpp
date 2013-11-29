/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Game.h"

#include <vector>

#include "util/Sysout.h"
#include "util/Sysin.h"
#include "util/SentenceStateBuilder.h"

#include "command/CmdDictionary.h"

#include "language/Grammar.h"

#include "expanse/Expanse.h"
#include "expanse/World.h"
#include "expanse/Area.h"
#include "expanse/Portal.h"
#include "expanse/Entity.h"
#include "expanse/Script.h"
#include "expanse/PlayerScript.h"
#include "expanse/StringValue.h"

Game::Game()
: running(false)
{
    nodeExpanse = new exp::Expanse();
}

void Game::run()
{

    addPlayer("Dylan");


    // We are running now
    running = true;

    // Last input vector
    std::vector<std::string> lastInput;

    // While running, run!
    while(running)
    {
        // Prompt
        Sysout::print("FCM:\\>"); Sysin::getWordsLowercase(&lastInput);
        Sysout::println();

        // Run command from the raw input
        bool success = runCommandFromRawInput(&lastInput);
        if(!success)
        {
            // Inform
            #ifdef DEBUG
            Sysout::print("Could not understand input: ");
            Sysout::println(Sysout::toFriendlyString(&lastInput));
            #endif // DEBUG
            Sysout::println("Misunderstanding.");
            Sysout::println();
        }
    }
}

void Game::load()
{
    new exp::World("Earth", nodeExpanse);
    new exp::Area("Ocean", nodeExpanse->getChild("Earth"));
    new exp::Area("Jungle", nodeExpanse->getChild("Earth"));
    new exp::Area("Desert", nodeExpanse->getChild("Earth"));
    new exp::Area("Plains", nodeExpanse->getChild("Earth"));
    new exp::Area("Forest", nodeExpanse->getChild("Earth"));

    Node* theSpawnPoint = new exp::Entity("_SpawnPoint", nodeExpanse->getChild("Earth")->getChild("Forest"));

    nodeSpawnAreaChild = theSpawnPoint;

    nodeExpanse->printHeirachy(0);
}

void Game::addPlayer(std::string playerName)
{
    Node* thePlayer = new exp::Entity("Player", nodeSpawnAreaChild->getParent());
    new exp::PlayerScript("PlayerScript", thePlayer);
    new exp::StringValue("PlayerName", thePlayer, playerName);
}

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
