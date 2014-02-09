/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Libirid_Game.h"

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

#include <iostream>

// Node Stuff
// ==========
#include "node/Node.h"

#include "node/TickableNode.h"

#include "node/Node_Expanse.h"
#include "node/Node_World.h"
#include "node/Node_Area.h"
#include "node/Node_Portal.h"
#include "node/Node_Entity.h"
#include "node/Node_Script.h"
#include "node/Node_PlayerScript.h"
#include "node/Node_StringValue.h"
#include "node/Node_Folder.h"

// Initialize
Libirid_Game::Libirid_Game(node::Node_Expanse* nodeExpanse, node::Node_Folder* nodeConcepts)
: nodeExpanse(nodeExpanse),
nodeConcepts(nodeConcepts)
{
}

// Finalize
Libirid_Game::~Libirid_Game()
{
}

//
void Libirid_Game::doTick()
{
    std::cout << "tick" << std::endl;

    for(auto it = tickableNodes.begin(); it != tickableNodes.end(); ++ it)
    {
        (*it)->tickIfReady();
    }
}

//
void Libirid_Game::findTickableNodes()
{
    nodeExpanse->getTickableDescendants(&tickableNodes);

    // Remove all the deconstructor nodes
    for(auto it = tickableNodes.begin(); it != tickableNodes.end(); ++ it)
    {
        node::TickableNode* tn = *it;

        if(tn->getName().front() == '~')
        {
            tickableNodes.erase(it);
        }
    }
}
