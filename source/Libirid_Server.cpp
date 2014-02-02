/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Libirid_Server.h"

#include <iostream>

#include <chrono>

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

//
Libirid_Server::Libirid_Server() {}

// When we are deleted
Libirid_Server::~Libirid_Server()
{
    // Delete our stuff too
    delete game;
}

// Run a single tick
void Libirid_Server::doTick()
{
    // Run a single game tick
    game->doTick();
}

void Libirid_Server::run()
{
    // Load Concepts
    // =============
    node::Node_Folder* loadedConcepts = new node::Node_Folder("concepts", nullptr);

    // Load Expanse
    // ============
    node::Node_Expanse* loadedExpanse = new node::Node_Expanse(0LL);


    // Initialization
    // ==============

    // Make a new game
    Libirid_Game game(loadedExpanse, loadedConcepts);

    // How fast should the ticks be in ms
    pulseRate = 1000;

    // Ticking handling
    typedef std::chrono::high_resolution_clock SuperClock;
    typedef std::chrono::milliseconds Milliseconds;

    // Clock stuff
    // ===========

    // Variable to hold when the last tick began
    auto whenLastTickBegan = SuperClock::now();

    // Do this forever
    while(true)
    {
        // If the game is paused
        if(isPaused)
        {
            // don't tick
            continue;
        }

        // Measure how long it has been since we last ticked
        int timeSinceLastTickBegan = (std::chrono::duration_cast<Milliseconds>(SuperClock::now() - whenLastTickBegan)).count();

        // If it's time to tick, then do so
        if(timeSinceLastTickBegan >= pulseRate)
        {
            // Remember when we started calculating this tick
            whenLastTickBegan = SuperClock::now();

            // Calculate game logic
            game.doTick();

            // Debug stuff: if a tick took longer than allowed, then report it
            #ifdef DEBUG
            int howLongThatTickTook = (std::chrono::duration_cast<Milliseconds>(SuperClock::now() - whenLastTickBegan)).count();
            if(howLongThatTickTook >= pulseRate)
            {
                std::cout << "Could not keep up! Took " << howLongThatTickTook << " to tick, but deadline is " << pulseRate << "!" << std::endl;
            }
            #endif // DEBUG
        }
    }

    // Delete self
    delete this;
}

void Libirid_Server::pause()
{
    isPaused = true;
}

void Libirid_Server::unpause()
{
    isPaused = false;
}

void Libirid_Server::receiveInput(std::string input)
{

}

void Libirid_Server::sendMessage(std::string message)
{

}
