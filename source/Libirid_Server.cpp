/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Libirid_Server.h"

#include <iostream>

Libirid_Server::Libirid_Server() { initialize(); }
Libirid_Server::~Libirid_Server() { finalize(); }

// Initialize
void Libirid_Server::initialize()
{
    //
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
    while(true)
    {
        std::cout << numbah << std::endl;
    }
}

void Libirid_Server::receiveInput(std::string input)
{

}

void Libirid_Server::sendMessage(std::string message)
{

}
