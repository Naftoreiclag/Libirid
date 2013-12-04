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
#include "expanse/Node.h"

#include "expanse/Expanse.h"
#include "expanse/World.h"
#include "expanse/Area.h"
#include "expanse/Portal.h"
#include "expanse/Entity.h"
#include "expanse/Script.h"
#include "expanse/PlayerScript.h"
#include "expanse/StringValue.h"

//
#include "SimpleClass.h"

//  Lua Stuff
// ===========
#include "luaStuff.h"

#include <iostream>

struct Donkey
{
    int donkeyVar;
};

// Initialize
Game::Game()
: isRunning(false)
{
    // Important nodes
    nodeExpanse = new exp::Expanse();
    nodeSpawnAreaChild = NULL;

    // Lua State
    luaState = luaL_newstate();
    std::cout << luabridge::getGlobalNamespace(luaState);

    //luabridge::getGlobalNamespace(luaState)
        //.beginClass<Donkey>("Donkey")
            //.addFunction("sayFoo", &SimpleClass::sayFoo)
        //.endClass();
        /*.beginClass<exp::Expanse> ("Expanse")
            //.addProperty("parent", &Node::getParent)
            .addFunction("sayFoo", &exp::Expanse::sayFoo)
        .endClass()
        .addVariable("dexp", &nodeExpanse)*/
}

// Finalize
Game::~Game()
{
    // Do something
}

// Run
void Game::run()
{

    //luaL_dostring(luaState, "egg.dexp:sayFoo()");

    addPlayer("Dylan");

    nodeExpanse->printHeirachy(0);


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

        // Run command from the raw input
        //bool success = runCommandFromRawInput(&lastInput);
        /*if(!success)
        {
            // Inform
            #ifdef DEBUG
            Sysout::print("Could not understand input: ");
            Sysout::println(Sysout::toFriendlyString(&lastInput));
            #endif // DEBUG
            Sysout::println("Misunderstanding.");
            Sysout::println();
        }*/
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
}

void Game::addPlayer(std::string playerName)
{
    Node* thePlayer = new exp::Entity("Player", nodeSpawnAreaChild->getParent());
    new exp::PlayerScript("PlayerScript", thePlayer);
    new exp::StringValue("PlayerName", thePlayer, playerName);
}
