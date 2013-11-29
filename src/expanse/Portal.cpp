/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Portal.h"

exp::Portal::Portal(std::string name, Node* parent)
: Node(name, NT_PORTAL, parent)
{
    //ctor
}

exp::Portal::~Portal()
{
    //dtor
}
