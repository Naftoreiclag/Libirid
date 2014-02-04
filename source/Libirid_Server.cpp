/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Libirid_Server.h"

#include <iostream>
#include <fstream>

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

void Libirid_Server::run()
{
    // Load Concepts
    // =============

    // Load
    node::Node_Folder* loadedConcepts = new node::Node_Folder("concepts", nullptr);

    // Load Expanse
    // ============

    // Load
    node::Node_Expanse* loadedExpanse;
    try
    {
        loadedExpanse = loadExpanse("../builds/save");
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    }

    // Initialization
    // ==============

    // Make a new game
    game = new Libirid_Game(loadedExpanse, loadedConcepts);

    // How fast should the ticks be in ms
    pulseRate = 1000;

    // Ticking handling
    typedef std::chrono::high_resolution_clock SuperClock;
    typedef std::chrono::milliseconds Milliseconds;

    // Tick Timing
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
        unsigned int timeSinceLastTickBegan = (std::chrono::duration_cast<Milliseconds>(SuperClock::now() - whenLastTickBegan)).count();

        // If it's time to tick, then do so
        if(timeSinceLastTickBegan >= pulseRate)
        {
            // Remember when we started calculating this tick
            whenLastTickBegan = SuperClock::now();

            // Calculate game logic
            game->doTick();

            // Debug stuff: if a tick took longer than allowed, then report it
            #ifdef DEBUG
            unsigned int howLongThatTickTook = (std::chrono::duration_cast<Milliseconds>(SuperClock::now() - whenLastTickBegan)).count();
            if(howLongThatTickTook >= pulseRate)
            {
                std::cout << "Could not keep up! Took " << howLongThatTickTook << " to tick, but deadline is " << pulseRate << "!" << std::endl;
            }
            #endif // DEBUG
        }
    }

    // Clean Up
    // ========

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

// Load
node::Node_Expanse* Libirid_Server::loadExpanse(std::string saveFileName)
{
    // Make a new expanse to return
    node::Node_Expanse* nodeExpanse = new node::Node_Expanse(0LL);

    // Load file
    std::ifstream saveFile(saveFileName);

    // Check if we could not open the file for some reason
    if(!saveFile.is_open())
    {
        throw "Could not open file " + saveFileName;
    }

    // Make a string to hold the statement
    std::string statement;

    // Iterate through all statements
    while(std::getline(saveFile, statement))
    {
        // Iterator through chars
        auto charPtr = statement.begin();

        // Get what type this is ===========

        // Store the type name
        std::string nodeTypeStr = "";

        // While this is not the end
        while(charPtr != statement.end())
        {
            // If this is a space
            if(*charPtr == ' ')
            {
                // Skip it
                ++ charPtr;
                continue;
            }

            // If we reach the colon
            if(*charPtr == ':')
            {
                // Break, because now we finished finding the name
                // Skip the char and break loop
                ++ charPtr;
                break;
            }

            // Valid char
            nodeTypeStr += *charPtr;

            ++ charPtr;
        }

        // Get name and path ========================

        // Store the name of the node that is currently being processed
        std::string nodeName = "";

        // Simultaneously construct a pointer to the right parent
        node::Node* parentNodePtr;

        // While this is not the end of the statement
        while(charPtr != statement.end())
        {
            // If this is a space
            if(*charPtr == ' ')
            {
                // Skip it
                ++ charPtr;
                continue;
            }

            // If this is a dot, then continue finding the path
            if(*charPtr == '.')
            {
                // If the name is Expanse, that is special
                if(nodeName == "expanse")
                {
                    // Because we mean to get the expanse
                    parentNodePtr = nodeExpanse;
                }

                // Otherwise
                else
                {
                    // Try find the parent
                    parentNodePtr = parentNodePtr->getChild(nodeName);

                    // Check for errors
                    if(parentNodePtr == nullptr)
                    {
                        throw "Could not find node referenced by " + statement + "!";
                    }
                }

                // Reset the name of the node, since we were finding the parent in actuality
                nodeName = "";

                // Skip the dot
                ++ charPtr;
                continue;
            }

            // Valid char
            nodeName += *charPtr;

            ++ charPtr;
        }

        // Make it ==========================
        if(nodeTypeStr == "World")
        {
            new node::Node_World(nodeName, parentNodePtr);
        }
        else if(nodeTypeStr == "Area")
        {
            new node::Node_Area(nodeName, parentNodePtr);
        }
        else if(nodeTypeStr == "Entity")
        {
            new node::Node_Entity(nodeName, parentNodePtr);
        }
    }

    // Close it when we are done
    saveFile.close();

    //
    return nodeExpanse;
}

void Libirid_Server::receiveInput(std::string input)
{

}

void Libirid_Server::sendMessage(std::string message)
{

}
