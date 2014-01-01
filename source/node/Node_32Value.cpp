/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_32Value.h"

using namespace node;

Node_32Value::Node_32Value(std::string name, Node* parent, int value)
: Node(name, NT_32VALUE, parent),
value(value)
{
    //ctor
}

Node_32Value::~Node_32Value()
{
    //dtor
}
