#ifndef POTATO_H
#define POTATO_H

#include "Luastuff.h"

class Potato
{
    public:
        int tastiness;
        int bounciness;

        Potato();

        void luaify(lua_State* luaState);
};

#endif // POTATO_H
