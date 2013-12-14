/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Game.h"

#include <vector>

#include "util/Sysout.h"
#include "util/Sysin.h"
#include "util/SentenceStateBuilder.h"

#include "language/Grammar.h"

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

#include "cmd/internalscripts/Dance.h"

int foop(int a, int b)
{
    //
}

#include <iostream>

//  Command Stuff
// ===============
#include "cmd/CmdDictionary.h"

// Initialize
Game::Game()
: isRunning(false)
{
    // Important nodes
    nodeExpanse = new node::Node_Expanse();
    nodeSpawnAreaChild = NULL;

    // Load commands
    cmdDict = cmd::CmdDictionary::getInstance();
    cmdDict->newCmdScriptInternal(cmd::scr::dance);
}

// Finalize
Game::~Game()
{
    // Delete everything
    delete nodeExpanse;
    delete cmdDict;
}

// Run
void Game::run()
{
//script::ScriptCommand* egg = new script::ScriptCommand(foop);

    //egg->execute(1, 2);

    // Detect spawn point
    nodeSpawnAreaChild = nodeExpanse->getDescendant("_SpawnPoint");

    // We are running now
    isRunning = true;

    // Last input vector
    std::vector<std::string> lastInput;

    // While running, run!
    while(isRunning)
    {
        // Prompt
        Sysout::print("FCM:\\>"); Sysin::getWordsLowercase(&lastInput);
        Sysout::println();
    }
}

// Load
void Game::load()
{
    new node::Node_World("Earth", nodeExpanse);
    new node::Node_Area("Ocean", nodeExpanse->getChild("Earth"));
    new node::Node_Area("Jungle", nodeExpanse->getChild("Earth"));
    new node::Node_Area("Desert", nodeExpanse->getChild("Earth"));
    new node::Node_Area("Plains", nodeExpanse->getChild("Earth"));
    new node::Node_Area("Forest", nodeExpanse->getChild("Earth"));
    new node::Node_Entity("_SpawnPoint", nodeExpanse->getChild("Earth")->getChild("Forest"));
}

// Add player
void Game::addPlayer(std::string playerName)
{
    node::Node* thePlayer = new node::Node_Entity("Player", nodeSpawnAreaChild->getParent());
    new node::Node_PlayerScript("PlayerScript", thePlayer);
    new node::Node_StringValue("PlayerName", thePlayer, playerName);
}
