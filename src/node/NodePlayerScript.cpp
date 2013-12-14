/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "NodePlayerScript.h"

using namespace node;

NodePlayerScript::NodePlayerScript(std::string name, Node* parent)
: Node(name, NT_PLAYERSCRIPT, parent)
{
}

NodePlayerScript::~NodePlayerScript()
{
    //dtor
}
