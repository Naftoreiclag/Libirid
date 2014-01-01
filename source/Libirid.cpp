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

    void initialize() {}
    void finalize() {}

    void run()
    {
        initialize();

        tthread::thread serverThread(runServer, nullptr);
        tthread::thread clientThread(runClient, nullptr);

        while(true){}

        finalize();
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
