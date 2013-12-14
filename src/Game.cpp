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

#include "node/NodeExpanse.h"
#include "node/NodeWorld.h"
#include "node/NodeArea.h"
#include "node/NodePortal.h"
#include "node/NodeEntity.h"
#include "node/NodeScript.h"
#include "node/NodePlayerScript.h"
#include "node/NodeStringValue.h"

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
    nodeExpanse = new node::NodeExpanse();
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
    new node::NodeWorld("Earth", nodeExpanse);
    new node::NodeArea("Ocean", nodeExpanse->getChild("Earth"));
    new node::NodeArea("Jungle", nodeExpanse->getChild("Earth"));
    new node::NodeArea("Desert", nodeExpanse->getChild("Earth"));
    new node::NodeArea("Plains", nodeExpanse->getChild("Earth"));
    new node::NodeArea("Forest", nodeExpanse->getChild("Earth"));
    new node::NodeEntity("_SpawnPoint", nodeExpanse->getChild("Earth")->getChild("Forest"));
}

// Add player
void Game::addPlayer(std::string playerName)
{
    node::Node* thePlayer = new node::NodeEntity("Player", nodeSpawnAreaChild->getParent());
    new node::NodePlayerScript("PlayerScript", thePlayer);
    new node::NodeStringValue("PlayerName", thePlayer, playerName);
}
