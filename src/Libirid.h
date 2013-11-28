/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef LIBIRID_H
#define LIBIRID_H

#include "Game.h"

class Libirid
{
    public:
        static bool inDebug();
        static void run();
        static Game* runningGame;
    private:
        static bool debugMode;
};

#endif // LIBIRID_H
