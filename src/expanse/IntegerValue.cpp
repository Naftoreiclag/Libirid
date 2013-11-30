/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "IntegerValue.h"

exp::IntegerValue::IntegerValue(std::string name, Node* parent, int value)
: Node(name, NT_INTEGERVALUE, parent),
value(value)
{
    //ctor
}

exp::IntegerValue::~IntegerValue()
{
    //dtor
}
