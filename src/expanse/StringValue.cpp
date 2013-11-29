/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "StringValue.h"

exp::StringValue::StringValue(std::string name, Node* parent, std::string value)
: Node(name, NT_STRINGVALUE, parent),
value(value)
{
    //ctor
}

exp::StringValue::~StringValue()
{
    //dtor
}
