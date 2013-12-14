/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "NodeArea.h"

using namespace node;

NodeArea::NodeArea(std::string name, Node* parent)
: Node(name, NT_AREA, parent)
{
}

NodeArea::~NodeArea()
{
    //dtor
}
