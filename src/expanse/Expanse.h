#ifndef EXPANSE_H
#define EXPANSE_H

#include <map>
#include <string>

#include "World.h"
#include "Entity.h"

namespace exp
{
    class Expanse
    {
        public:
            Expanse();
            virtual ~Expanse();
        private:
            std::map<std::string, exp::World> worlds;
            std::vector<exp::Entity> entities;
    };
}

#endif // EXPANSE_H
