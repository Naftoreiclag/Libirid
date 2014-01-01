/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_64Value.h"

using namespace node;

Node_64Value::Node_64Value(std::string name, Node* parent, int value)
: Node(name, NT_64VALUE, parent),
value(value)
{
    //ctor
}

Node_64Value::~Node_64Value()
{
    //dtor
}
