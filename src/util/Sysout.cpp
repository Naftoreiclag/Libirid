#include "Sysout.h"

#include <iostream>
#include <string>

void Sysout::print(std::string str)
{
    std::cout << str;
}

void Sysout::println(std::string str)
{
    std::cout << str << std::endl;
}

void Sysout::println()
{
    std::cout << std::endl;
}

Sysout::Sysout() {}
