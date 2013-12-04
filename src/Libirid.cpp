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
        // Initialize
        initialize();

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

        // Clean-up
        finalize();
    }
}

// This is where the magic happens
int main()
{
    // Run
    Libirid::run();

    // Died quietly
    return 0;
}
