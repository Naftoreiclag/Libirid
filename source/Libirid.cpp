/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
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

//
namespace Libirid
{
    Libirid_Server server;
    Libirid_Client client;

    void runServer(void* _) { server.run(); }
    void runClient(void* _) { client.run(); }

    void run()
    {
        // Declare that this is the creature version
        std::cout << "This is the creature version." << std::endl;

        // Run the server on a new thread
        tthread::thread serverThread(runServer, nullptr);

        // Run the client on this thread
        runClient(nullptr);
    }
}

// This is where the magic begins
int main()
{
    // Run the application
    Libirid::run();

    // Ended with hopefully no problems
    return 0;
}
