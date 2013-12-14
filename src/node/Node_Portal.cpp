/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_Portal.h"

using namespace node;

Node_Portal::Node_Portal(std::string name, Node* parent, std::string exitAreaName)
: Node(name, NT_PORTAL, parent)
{
    //ctor
}

Node_Portal::~Node_Portal()
{
    //dtor
}
