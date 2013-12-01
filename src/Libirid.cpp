/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "util/Sysout.h"

#include "Game.h"

#include "Luastuff.h"

#include "Filestuff.h"

#include "Potato.h"
#include "scriptloader/ScriptLibrary.h"

#include "cmd/CmdDictionary.h"

// Print lua errors (Gee, this place is becoming a mess...)
void printLuaErrors(lua_State* luaState, int luaScript)
{
    // Does something
    if(luaScript != 0)
    {
        // Print the error message
        Sysout::println(lua_tostring(luaState, -1));

        // Removes that error message
        lua_pop(luaState, 1);
    }
}

// Initialize
void initialize()
{
    // Set the display width to 80 chars long (for word-wrap)
    Sysout::setDisplayWidth(80);

    // If we are in debug mode, then print that
    #ifdef DEBUG
    Sysout::println("Running in DEBUG mode!");
    Sysout::printDictionaryEntries();
    #endif
}

// Run
void run()
{
    bool running = true;

    while(running)
    {
        // Put a title screen here

        // Run a game
        Game* game = new Game();
        game->load();
        game->run();
        delete game;
    }
}

// Finalize
void finalize()
{

}

int main()
{
    Potato potato;

    lua_State* luaState;
    luaState = luaL_newstate();

    luaL_openlibs(luaState);

    potato.luaify(luaState);

    int luaScript = luaL_dofile(luaState, getLocalFilePath("potatoProp.lua"));

    printLuaErrors(luaState, luaScript);

    Sysout::println(potato.tastiness);
    Sysout::println(potato.bounciness);

    lua_close(luaState);

    cmd::CmdScriptLua luascr("hello");

    luascr.execute();

    ScriptLibrary::getInstance()->loadLua(getLocalFilePath("potatoProp.lua"));

    // Initialize
    initialize();

    // Run
    run();

    // Clean-up
    finalize();

    // Died quietly
    return 0;
}
