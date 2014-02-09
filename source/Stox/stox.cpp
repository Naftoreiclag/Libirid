/* Copyright (c) 2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Stox is distributed under Public Domain (http://unlicense.org/)
 *
 * This software is in the public domain, furnished "as is", without technical
 * support, and with no warranty, express or implied, as to its usefulness for
 * any purpose.
 *
 * See accompanying file LICENSE
 */

#include "stox.hpp"

#include <string>
#include <sstream>

#define MACRO_STOX_CONV val; std::istringstream iss(str); iss >> val; return val

namespace stox
{
    short stos(std::string str)
    {
        short MACRO_STOX_CONV;
    }
    unsigned short stous(std::string str)
    {
        unsigned short MACRO_STOX_CONV;
    }
    int stoi(std::string str)
    {
        int MACRO_STOX_CONV;
    }
    unsigned int stoui(std::string str)
    {
        unsigned int MACRO_STOX_CONV;
    }
    long stol(std::string str)
    {
        long MACRO_STOX_CONV;
    }
    unsigned long stoul(std::string str)
    {
        unsigned long MACRO_STOX_CONV;
    }
    long long stoll(std::string str)
    {
        long MACRO_STOX_CONV;
    }
    unsigned long long stoull(std::string str)
    {
        unsigned long long MACRO_STOX_CONV;
    }
}
