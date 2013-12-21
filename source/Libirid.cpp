/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

/* The Libirid application
 *
 */

#include "Libirid_Title.h"

#include "Libirid_Options.h"
#include "Libirid_PersonalityFactory.h"

#include "Libirid_Server.h"
#include "Libirid_Client.h"

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
            if(choice == 1 || choice == 3)
            {
                // Make a new client
                Libirid_Client client;

                // Make a new server
                Libirid_Server server;
            }

            // Player creation
            else if(choice == 2)
            {

            }

            // Join game
            else if(choice == 4356789)
            {

            }

            // Adjust Settings
            else if(choice == 4)
            {

            }

            // Exit Program
            else if(choice == 5)
            {
                appIsRunning = false;
            }
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
