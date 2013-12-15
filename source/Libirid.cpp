/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

/* The Libirid application
 *
 */

#include "Game.h"

namespace Libirid
{
    // Initialize
    void initialize()
    {
        // Do something
    }

    // Finalize
    void finalize()
    {
        // Do something
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
}

// This is where the magic happens
int main()
{
    // Initialize
    Libirid::initialize();

    // Run
    Libirid::run();

    // Clean-up
    Libirid::finalize();

    // Died quietly
    return 0;
}
