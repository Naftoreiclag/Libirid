#include "SimpleClass.h"

#include <iostream>

SimpleClass::SimpleClass()
{
    //ctor
}

SimpleClass::~SimpleClass()
{
    //dtor
}

void SimpleClass::sayFoo()
{
    std::cout << "It's a foo pie!" << std::endl;
}
