/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_Entity.h"

using namespace node;

Node_Entity::Node_Entity(std::string name, Node* parent)
: Node(name, NT_ENTITY, parent)
{

}

Node_Entity::~Node_Entity()
{
    //dtor
}
