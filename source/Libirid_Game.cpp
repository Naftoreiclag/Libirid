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
    // BEGIN FAKE GAME LOADING

    new node::Node_World("Earth", nodeExpanse);
    new node::Node_Area("Ocean", nodeExpanse->getChild("Earth"));
    new node::Node_Area("Jungle", nodeExpanse->getChild("Earth"));
    new node::Node_Area("Desert", nodeExpanse->getChild("Earth"));
    new node::Node_Area("Plains", nodeExpanse->getChild("Earth"));
    new node::Node_Area("Forest", nodeExpanse->getChild("Earth"));
    new node::Node_Entity("_SpawnPoint", nodeExpanse->getChild("Earth")->getChild("Forest"));

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
