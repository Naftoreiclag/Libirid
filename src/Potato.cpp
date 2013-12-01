#include "Potato.h"

Potato::Potato()
: tastiness(6),
bounciness(9)
{
}

void Potato::luaify(lua_State* luaState)
{
    luabridge::getGlobalNamespace(luaState)
        .beginNamespace("Potato")
            .beginNamespace("Properties")
                .addVariable("tastiness", &tastiness)
                .addVariable("bounciness", &bounciness)
            .endNamespace()
        .endNamespace();
}
