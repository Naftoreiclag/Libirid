/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Area.h"

exp::Area::Area(std::string name, Node* parent)
: Node(name, NT_AREA, parent)
{
}

exp::Area::~Area()
{
    //dtor
}
