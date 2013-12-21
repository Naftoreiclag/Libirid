/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef LIBIRID_TITLE_H
#define LIBIRID_TITLE_H

#include <string>

class Title
{
    public:
        static void getInformativeMessageBasedOnFailNumber(int numFails);
        void printPrettyScreen(std::string centerifier, char solid);
        int run();
};

#endif // LIBIRID_TITLE_H
