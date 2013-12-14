/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_Area.h"

using namespace node;

Node_Area::Node_Area(std::string name, Node* parent)
: Node(name, NT_AREA, parent)
{
}

Node_Area::~Node_Area()
{
    //dtor
}
