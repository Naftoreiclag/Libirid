/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_ByteValue.h"

using namespace node;

Node_ByteValue::Node_ByteValue(std::string name, Node* parent, int value)
: Node(name, NT_BYTEVALUE, parent),
value(value)
{
    //ctor
}

Node_ByteValue::~Node_ByteValue()
{
    //dtor
}
