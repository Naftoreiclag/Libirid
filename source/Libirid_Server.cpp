/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Libirid_Server.h"

#include <iostream>

#include <chrono>

Libirid_Server::Libirid_Server() { initialize(); }
Libirid_Server::~Libirid_Server() { finalize(); }

// Initialize
void Libirid_Server::initialize()
{
    pulseRate = 1000;
}

// Finalize
void Libirid_Server::finalize()
{

}

// Run a single tick
void Libirid_Server::doTick()
{
    // Do something


    // Increment age
    ++ expanseAge;
}

void Libirid_Server::run()
{
    //
    initialize();

    // Ticking
    typedef std::chrono::high_resolution_clock SuperClock;
    typedef std::chrono::milliseconds Milliseconds;

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

    //
    finalize();
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
