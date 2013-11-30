/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef CARDINAL_H
#define CARDINAL_H

#include <string>

class Point3i;

class Cardinal
{
    public:
        static Point3i interpretString(std::string str);
};

#endif // CARDINAL_H
