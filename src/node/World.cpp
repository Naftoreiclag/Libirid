/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "World.h"

using namespace node;

World::World(std::string name, Node* parent)
: Node(name, NT_WORLD, parent)
{
    //ctor
}

World::~World()
{
    //dtor
}
