/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

/* The Libirid application
 *
 */

#include "Title.h"

#include "Server.h"
#include "Client.h"

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
        bool appIsRunning = true;

        while(appIsRunning)
        {
            Title title;
            int choice = title.run();

            // Return to game
            if(choice == 1)
            {

            }

            // Player creation
            else if(choice == 2)
            {

            }

            // Join game
            else if(choice == 3)
            {

            }

            // Adjust Settings
            else if(choice == 4)
            {

            }

            // Exit Program
            else if(choice = 5)
            {
                appIsRunning = false;
            }
        }

        // Make a new client
        Client client;

        // Make a new server
        Server server;
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
