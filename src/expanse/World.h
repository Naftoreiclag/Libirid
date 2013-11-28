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
