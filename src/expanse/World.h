/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <string>

#include "Area.h"

namespace exp
{
    class World
    {
        public:
            World();
            virtual ~World();
        private:
            std::vector<Area> areas;
    };
}

#endif // WORLD_H
