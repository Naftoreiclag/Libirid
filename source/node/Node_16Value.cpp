/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_16Value.h"

using namespace node;

Node_16Value::Node_16Value(std::string name, Node* parent, int value)
: Node(name, NT_16VALUE, parent),
value(value)
{
    //ctor
}

Node_16Value::~Node_16Value()
{
    //dtor
}
