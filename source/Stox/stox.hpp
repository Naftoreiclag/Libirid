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

#ifndef STOX_H
#define STOX_H

#include <string>

namespace stox
{
    short              stos   (std::string str);
    unsigned short     stous  (std::string str);
    int                stoi   (std::string str);
    unsigned int       stoui  (std::string str);
    long               stol   (std::string str);
    unsigned long      stoul  (std::string str);
    long long          stoll  (std::string str);
    unsigned long long stoull (std::string str);
}

#endif // STOX_H
