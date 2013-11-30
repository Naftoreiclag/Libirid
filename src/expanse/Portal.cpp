/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Portal.h"

exp::Portal::Portal(std::string name, Node* parent, std::string exitAreaName)
: Node(name, NT_PORTAL, parent)
{
    //ctor
}

exp::Portal::~Portal()
{
    //dtor
}
