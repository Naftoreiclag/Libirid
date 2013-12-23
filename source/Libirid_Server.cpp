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
    pulseRate = 750;
}

// Finalize
void Libirid_Server::finalize()
{

}

// Run a single tick
void Libirid_Server::doTick()
{
    // Do something
    std::cout << expanseAge << std::endl;

    long long big = 99999999 + expanseAge;
    long long foo = 1;
    for(long long i = expanseAge; i < big; ++ i)
    {
        foo += i * i;
    }
    std::cout << "got " << foo << std::endl;

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

    while(true)
    {
        int timeSinceLastTickBegan = (std::chrono::duration_cast<Milliseconds>(SuperClock::now() - whenLastTickBegan)).count();
        if(timeSinceLastTickBegan >= pulseRate)
        {
            whenLastTickBegan = SuperClock::now();
            doTick();
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
