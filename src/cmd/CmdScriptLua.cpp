/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "CmdScriptLua.h"

#include <string>

#include "../Luastuff.h"

#include <iostream>

using namespace cmd;

// Print lua errorz (Gee, this place is becoming a mess...)
void printLuaErrorz(lua_State* luaState, int luaScript)
{
    // Does something
    if(luaScript != 0)
    {
        // Print the error message
        std::cout << lua_tostring(luaState, -1) << std::endl;

        // Removes that error message
        lua_pop(luaState, 1);
    }
}

CmdScriptLua::CmdScriptLua(std::string* code)
: CmdScript(SRT_LUA),
code(code)
{
}

void CmdScriptLua::execute()
{
    lua_State* luaState;
    luaState = luaL_newstate();

    std::cout << "running da scrip" << std::endl;

    // so we can print bro
    luaL_openlibs(luaState);

    int luaScript = luaL_dostring(luaState, (*code).c_str());
    printLuaErrorz(luaState, luaScript);

    lua_close(luaState);
}
