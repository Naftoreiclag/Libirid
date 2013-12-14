/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "NodeScript.h"

using namespace node;

NodeScript::NodeScript(std::string name, Node* parent)
: Node(name, NT_SCRIPT, parent)
{
}

NodeScript::~NodeScript()
{
    //dtor
}
