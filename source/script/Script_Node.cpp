/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Script_Node.h"

using namespace script;

Script_Node::Script_Node(NodeFunction func)
: Script(),
function(func)
{
}

Script_Node::~Script_Node()
{
}

char Script_Node::execute(int a, int b)
{
    function(a, b);
}
