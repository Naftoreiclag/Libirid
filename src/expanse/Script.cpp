/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Script.h"

exp::Script::Script(std::string name, Node* parent)
: Node(name, NT_SCRIPT, parent)
{
}

exp::Script::~Script()
{
    //dtor
}
