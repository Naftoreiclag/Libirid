/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Node_Expanse.h"

using namespace node;

Node_Expanse::Node_Expanse(long long age)
: Node("Expanse", NT_EXPANSE, NULL),
age(age)
{
    //ctor
}

Node_Expanse::~Node_Expanse()
{
    //dtor
}

void Node_Expanse::incrementAge()
{
    ++ age;
}

long long Node_Expanse::getAge()
{
    return age;
}
