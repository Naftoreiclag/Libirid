/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Libirid_Server.h"

#include <iostream>

#include <chrono>

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
    // Initialization
    // ==============

    // Make a new game
    game = new Libirid_Game();

    // How fast should the ticks be in ms
    pulseRate = 1000;

    // Load the game map
    game->load();

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
            doTick();

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
