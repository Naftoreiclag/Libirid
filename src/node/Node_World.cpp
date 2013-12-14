/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_World.h"

using namespace node;

Node_World::Node_World(std::string name, Node* parent)
: Node(name, NT_WORLD, parent)
{
    //ctor
}

Node_World::~Node_World()
{
    //dtor
}
