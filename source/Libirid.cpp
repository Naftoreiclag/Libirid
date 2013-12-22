/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

/* The Libirid application
 *
 * #        #                      #
 * #        #                      #
 * #     #  #      #         #     #
 * #        #                      #
 * #   ###  ###  ###  # ## ###   ###
 * #     #  #  #   #  ##     #  #  #
 * #     #  #  #   #  #      #  #  #
 * #     #  #  #   #  #      #  #  #
 * ####  #  ###    #  #      #   ###
 *
 */

#include "Libirid_Title.h"

#include "Libirid_Options.h"
#include "Libirid_PersonalityFactory.h"

#include "Libirid_Server.h"
#include "Libirid_Client.h"

#include <chrono>
#include <iostream>

#include "TinyThread/tinythread.h"

namespace Libirid
{
    Libirid_Server server;
    Libirid_Client client;

    void runServer(void* _) { server.run(); }
    void runClient(void* _) { client.run(); }

    void initialize() {}
    void finalize() {}

    void run()
    {
        initialize();

        tthread::thread serverThread(runServer, nullptr);
        tthread::thread clientThread(runClient, nullptr);

        for(int i = 0; i < 9999999; ++i)
        {
            server.numbah = i;
        }

        finalize();
    }
}

int main()
{
    Libirid::run();

    return 0;
}

/*
namespace Libirid
{
    // Run
    void run()
    {
        bool appIsRunning = true;

        while(appIsRunning)
        {
            // Title Screen
            Title title;
            int choice = title.run();

            // Return to game
            if(choice == 1 || choice == 3)
            {
                tthread::thread serverThread()

                Libirid_Server server;

                Libirid_Client client;

            }

            // Player creation
            else if(choice == 2)
            {
            }

            // Join game
            else if(choice == 2332423432)
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

void threadTest(void* num)
{
    for(int i = 0; i < 123456789; ++ i)
    {
    }

    std::cout << "Hello threads1!" << std::endl;
}
void threadTest2(void* num)
{
    for(int i = 0; i < 12345678; ++ i)
    {
    }

    std::cout << "Hello threads2!" << std::endl;
}

// This is where the magic happens
int main()
{
    // Run
    Libirid::run();
    // Died quietly
    return 0;
}
*/
