/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "TickableNode.h"

using namespace node;

TickableNode::TickableNode(std::string name, NodeType nodeType, Node* parent)
: Node(name, nodeType, parent)
{
    //ctor
}

TickableNode::~TickableNode()
{
    //dtor
}
