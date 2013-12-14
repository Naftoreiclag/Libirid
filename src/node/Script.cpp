/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Script.h"

node::Script::Script(std::string name, Node* parent)
: Node(name, NT_SCRIPT, parent)
{
}

node::Script::~Script()
{
    //dtor
}
