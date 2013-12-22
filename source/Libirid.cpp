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
            if(choice == 1)
            {
                std::cout << "This will automatically do whatever you did last time. If you connected to a server with ip 12.345.678.910, then you will do that again. If you connected to localhost, then you will connect to localhost." std::endl;
            }

            // Player creation
            else if(choice == 2)
            {
                std::cout << "Player creation screen here" std::endl;
            }

            // Join game
            else if(choice == 3)
            {
                std::cout << "Connecting to ioeafkwfmwgreafdcaexryje." std::endl;

                Libirid_Client client;

                Libirid_Server server;

                while(true)
                {
                    server.doTick();

                    client.getString();
                }
            }

            // Adjust Settings
            else if(choice == 4)
            {
                std::cout << "Options screen here" std::endl;
            }

            // Exit Program
            else if(choice == 5)
            {
                std::cout << "Good-bye." std::endl;
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
