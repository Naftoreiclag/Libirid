/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Expanse.h"

using namespace node;

Expanse::Expanse()
: Node("Expanse", NT_EXPANSE, NULL)
{
    //ctor
}

Expanse::~Expanse()
{
    //dtor
}

#ifdef DEBUG
#include <iostream>
void Expanse::sayFoo()
{
    std::cout << "Foo!" << std::endl;
}
#endif
