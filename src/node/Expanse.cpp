/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Expanse.h"

node::Expanse::Expanse()
: Node("Expanse", NT_EXPANSE, NULL)
{
    //ctor
}

node::Expanse::~Expanse()
{
    //dtor
}

#ifdef DEBUG
#include <iostream>
void node::Expanse::sayFoo()
{
    std::cout << "Foo!" << std::endl;
}
#endif
