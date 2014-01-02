/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Libirid_Game.h"

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

#include <iostream>

//  Node Stuff
// ============
#include "node/Node.h"

#include "node/Node_Expanse.h"
#include "node/Node_World.h"
#include "node/Node_Area.h"
#include "node/Node_Portal.h"
#include "node/Node_Entity.h"
#include "node/Node_Script.h"
#include "node/Node_PlayerScript.h"
#include "node/Node_StringValue.h"
#include "node/Node_Folder.h"

// Initialize
Libirid_Game::Libirid_Game()
{
    // Make an expanse to store everything
    nodeExpanse = new node::Node_Expanse();

    // Make somewhere to store concepts
    nodeConcepts = new node::Node_Folder("concepts", nullptr);
}

// Finalize
Libirid_Game::~Libirid_Game()
{
    // Delete expanse
    delete nodeExpanse;

    // Delete concept folder
    delete nodeConcepts;
}

//
void Libirid_Game::doTick()
{
    std::cout << "tick" << std::endl;
}

// Load
void Libirid_Game::load()
{
    // Attempt to load the save file
    // Note: this path only works when running from CB's debug console
    // if running the .exe this should be changed to just "save"
    std::ifstream saveFile("../builds/save");

    // If the file is actually open
    if(saveFile.is_open())
    {
        // Make a string to hold the statement
        std::string statement;

        // Iterate through all statements
        while(std::getline(saveFile, statement))
        {
            // Iterator through chars
            auto charPtr = statement.begin();

            // Get what type this is ===========

            // Store the type name
            std::string nodeTypeStr = "";

            // While this is not the end
            while(charPtr != statement.end())
            {
                // If this is a space
                if(*charPtr == ' ')
                {
                    // Skip it
                    ++ charPtr;
                    continue;
                }

                // If we reach the colon
                if(*charPtr == ':')
                {
                    // Break, because now we finished finding the name
                    // Skip the char and break loop
                    ++ charPtr;
                    break;
                }

                // Valid char
                nodeTypeStr += *charPtr;

                ++ charPtr;
            }

            // Get path ========================
            std::string nodeName = "";
            node::Node* parentNodePtr;
            while(charPtr != statement.end())
            {
                // If this is a space
                if(*charPtr == ' ')
                {
                    // Skip it
                    ++ charPtr;
                    continue;
                }

                // If this is a dot
                if(*charPtr == '.')
                {
                    if(nodeName == "Expanse")
                    {
                        parentNodePtr = nodeExpanse;
                    }
                    else
                    {
                        parentNodePtr = parentNodePtr->getChild(nodeName);
                    }
                    nodeName = "";
                    ++ charPtr;
                    continue;
                }

                // Valid char
                nodeName += *charPtr;

                ++ charPtr;
            }

            // Make it ==========================
            if(nodeTypeStr == "World")
            {
                new node::Node_World(nodeName, parentNodePtr);
            }
            else if(nodeTypeStr == "Area")
            {
                new node::Node_Area(nodeName, parentNodePtr);
            }
            else if(nodeTypeStr == "Entity")
            {
                new node::Node_Entity(nodeName, parentNodePtr);
            }

            std::cout << "Creating a [" << nodeTypeStr << "] named [" << nodeName << "] and parented to [" << parentNodePtr->getName() << "]" << std::endl;
        }

        // Close it when we are done
        saveFile.close();
    }

    // File could not be opened
    else
    {
        // File must be missing
        std::cout << "File is missing!";
    }

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    nodeExpanse->printHeirachy(0);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;

    // BEGIN FAKE GAME LOADING
    /*new node::Node_World("Fooland", nodeExpanse);
    new node::Node_Area("Lake", nodeExpanse->getChild("Fooland"));
    new node::Node_Area("River", nodeExpanse->getChild("Fooland"));
    new node::Node_Area("Plains", nodeExpanse->getChild("Fooland"));
    new node::Node_Area("Forest", nodeExpanse->getChild("Fooland"));
    new node::Node_Entity("_SpawnPoint", nodeExpanse->getChild("Fooland")->getChild("Forest"));*/

    // END FAKE GAME LOADING

    // Detect spawn point
    nodeSpawnAreaChild = nodeExpanse->getDescendant("_SpawnPoint");
}

// Add player
void Libirid_Game::addPlayer(std::string playerName)
{
    node::Node* thePlayer = new node::Node_Entity("Player", nodeSpawnAreaChild->getParent());
    nodePlayerScript = new node::Node_PlayerScript("PlayerScript", thePlayer);
    new node::Node_StringValue("PlayerName", thePlayer, playerName);
}

// Process input
void Libirid_Game::runPlayerCommand(node::Node* nodePlayerScript, std::string theirInput)
{
    if(theirInput == "whereami")
    {
        std::cout << nodePlayerScript->getParent()->getParent()->getName();
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

///////////////
// Utilities //
///////////////

// Split words
void Libirid_Game::splitWordsLowercase(std::string line, std::vector<std::string>* wordList)
{
    std::stringstream sBuffer(line);
    std::string word;
    while(sBuffer >> word)
    {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        wordList->push_back(word);
    }
}
