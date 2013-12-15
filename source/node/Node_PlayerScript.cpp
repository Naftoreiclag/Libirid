/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_PlayerScript.h"

using namespace node;

Node_PlayerScript::Node_PlayerScript(std::string name, Node* parent)
: Node(name, NT_PLAYERSCRIPT, parent)
{
}

Node_PlayerScript::~Node_PlayerScript()
{
    //dtor
}
