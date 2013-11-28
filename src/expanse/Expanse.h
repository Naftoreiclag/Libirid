#ifndef EXPANSE_H
#define EXPANSE_H

#include <string>
#include <vector>
#include <map>

#include "Area.h"
#include "World.h"
#include "Entity.h"

namespace exp
{
    //typedef unsigned int areaId;

    //typedef unsigned int worldId;

    class Expanse
    {
        public:
            Expanse();
            virtual ~Expanse();
        private:

            // Worlds
            std::vector<exp::World> worlds;

            // Areas
            std::vector<exp::Area> areas;

            // Entities
            std::vector<exp::Entity> entities;

            /*// All areas
            std::vector<exp::Area> areas;
            //std::map<exp::areaId, exp::Area> areas;

            // All worlds
            //std::map<exp::worldId, exp::World> worlds;

            // All entities
            std::vector<exp::Entity> entities;

            // Get (area) children of a world
            std::map<exp::areaId, std::vector<*Entity>> entities;

            std::map<exp::worldId, std::vector<exp::areaId>> areasByWorld;
            std::map<exp::areaId, std::vector<*>>*/
    };
}

#endif // EXPANSE_H
