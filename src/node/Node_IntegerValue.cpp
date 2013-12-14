/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_IntegerValue.h"

using namespace node;

Node_IntegerValue::Node_IntegerValue(std::string name, Node* parent, int value)
: Node(name, NT_INTEGERVALUE, parent),
value(value)
{
    //ctor
}

Node_IntegerValue::~Node_IntegerValue()
{
    //dtor
}
