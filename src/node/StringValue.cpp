/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "StringValue.h"

using namespace node;

StringValue::StringValue(std::string name, Node* parent, std::string value)
: Node(name, NT_STRINGVALUE, parent),
value(value)
{
    //ctor
}

StringValue::~StringValue()
{
    //dtor
}
