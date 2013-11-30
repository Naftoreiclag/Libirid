/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "PlayerScript.h"

exp::PlayerScript::PlayerScript(std::string name, Node* parent)
: Node(name, NT_PLAYERSCRIPT, parent)
{
}

exp::PlayerScript::~PlayerScript()
{
    //dtor
}
