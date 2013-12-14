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

#include "node/Expanse.h"
#include "node/World.h"
#include "node/Area.h"
#include "node/Portal.h"
#include "node/Entity.h"
#include "node/Script.h"
#include "node/PlayerScript.h"
#include "node/StringValue.h"

#include "cmd/internalscripts/Dance.h"

#include <iostream>

//  Command Stuff
// ===============
#include "cmd/CmdDictionary.h"

// Initialize
Game::Game()
: isRunning(false)
{
    // Important nodes
    nodeExpanse = new node::Expanse();
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
    new node::World("Earth", nodeExpanse);
    new node::Area("Ocean", nodeExpanse->getChild("Earth"));
    new node::Area("Jungle", nodeExpanse->getChild("Earth"));
    new node::Area("Desert", nodeExpanse->getChild("Earth"));
    new node::Area("Plains", nodeExpanse->getChild("Earth"));
    new node::Area("Forest", nodeExpanse->getChild("Earth"));
    new node::Entity("_SpawnPoint", nodeExpanse->getChild("Earth")->getChild("Forest"));
}

// Add player
void Game::addPlayer(std::string playerName)
{
    node::Node* thePlayer = new node::Entity("Player", nodeSpawnAreaChild->getParent());
    new node::PlayerScript("PlayerScript", thePlayer);
    new node::StringValue("PlayerName", thePlayer, playerName);
}
