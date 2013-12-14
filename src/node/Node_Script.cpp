/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_Script.h"

using namespace node;

Node_Script::Node_Script(std::string name, Node* parent)
: Node(name, NT_SCRIPT, parent)
{
}

Node_Script::~Node_Script()
{
    //dtor
}
