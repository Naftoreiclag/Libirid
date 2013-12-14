/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "NodeEntity.h"

using namespace node;

NodeEntity::NodeEntity(std::string name, Node* parent)
: Node(name, NT_ENTITY, parent)
{

}

NodeEntity::~NodeEntity()
{
    //dtor
}
