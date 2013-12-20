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
        // Make a new client
        Client client;

        // Make a new server
        Server server;

        bool appIsRunning = true;
            Title title;
            title.run();

        while(appIsRunning)
        {

            //server.run();
            //client.getInput();
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
