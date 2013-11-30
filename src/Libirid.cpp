/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#include "Libirid.h"

#include "util/Point3i.h"

#include "Game.h"

#ifdef DEBUG
#include "util/Sysout.h"
#endif // DEBUG

// The running game instance
Game* Libirid::runningGame;

void Libirid::run()
{

    // If we are in debug mode, then print that
    #ifdef DEBUG
    Sysout::println("Running in DEBUG mode!");
    Sysout::printDictionaryEntries();
    #endif

    //
    bool running = true;

    //
    while(running)
    {
        // Run a game
        runningGame = new Game();
        runningGame->load();
        runningGame->run();
        delete runningGame;
    }
}
