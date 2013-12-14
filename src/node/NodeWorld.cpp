/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "NodeWorld.h"

using namespace node;

NodeWorld::NodeWorld(std::string name, Node* parent)
: Node(name, NT_WORLD, parent)
{
    //ctor
}

NodeWorld::~NodeWorld()
{
    //dtor
}
