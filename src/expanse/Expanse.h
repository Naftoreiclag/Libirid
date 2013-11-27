#ifndef EXPANSE_H
#define EXPANSE_H

#include <map>
#include <string>

#include "World.h"

class Expanse
{
    public:
        Expanse();
        virtual ~Expanse();
    private:
        std::map<std::string, World> worlds;
};

#endif // EXPANSE_H
