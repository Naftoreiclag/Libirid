/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Libirid_Server.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <chrono>

// Node Stuff
// ==========
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

// XML Stuff
// =========
#include "RapidXml/rapidxml.hpp"


//
Libirid_Server::Libirid_Server(unsigned int pulseRate, std::string expanseSave, std::string conceptsSave)
: pulseRate(pulseRate),
expanseSave(expanseSave),
conceptsSave(conceptsSave)
{}

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
        loadedExpanse = loadExpanse(expanseSave);
    }
    catch(std::string e)
    {
        std::cout << e << std::endl;
    }

    // Initialization
    // ==============

    // Make a new game
    game = new Libirid_Game(loadedExpanse, loadedConcepts);

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
using namespace rapidxml;
node::Node_Expanse* Libirid_Server::loadExpanse(std::string saveFileName)
{
    // The save XML document
    xml_document<> doc;

    // The generic document and vector buffer
    std::ifstream saveFile(saveFileName);

    // Check if we could not open the file for some reason
    if(!saveFile.is_open())
    {
        throw "Could not open file " + saveFileName;
    }


    std::stringstream buffer;
    buffer << saveFile.rdbuf();
    saveFile.close();
    std::string saveFileContent(buffer.str());
    doc.parse<0>(&saveFileContent[0]);
    xml_node<>* root_node = doc.first_node("expanse");
    for(xml_node<>* node = root_node->first_node(); node; node = node->next_sibling())
    {
        std::cout << node->first_attribute("name")->value();
    }
}
