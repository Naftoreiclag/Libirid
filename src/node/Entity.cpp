/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Entity.h"

using namespace node;

Entity::Entity(std::string name, Node* parent)
: Node(name, NT_ENTITY, parent)
{

}

Entity::~Entity()
{
    //dtor
}
