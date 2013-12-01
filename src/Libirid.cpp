/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "util/Sysout.h"

#include "Game.h"

#include "Lua_5-2-2/lua.h"
//#include "LuaBridge/luabridge.h"

// Initialize
void initialize()
{
    // Set the display width to 80 chars long (for word-wrap)
    Sysout::setDisplayWidth(80);

    Sysout::println(LUA_TTABLE);

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
    // Initialize
    initialize();

    // Run
    run();

    // Clean-up
    finalize();

    // Died quietly
    return 0;
}
