/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "NodeIntegerValue.h"

using namespace node;

NodeIntegerValue::NodeIntegerValue(std::string name, Node* parent, int value)
: Node(name, NT_INTEGERVALUE, parent),
value(value)
{
    //ctor
}

NodeIntegerValue::~NodeIntegerValue()
{
    //dtor
}
