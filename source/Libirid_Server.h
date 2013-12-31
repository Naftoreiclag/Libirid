/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef LIBIRID_SERVER_H
#define LIBIRID_SERVER_H

#include <string>

class Libirid_Server
{
    public:
        Libirid_Server();
        ~Libirid_Server();

        // Initialize server
        void initialize();

        // Finalize server
        void finalize();

        // Pauses the game
        void pause();

        // Resumes the game
        void unpause();

        // Does everything
        void run();

        // Executes a single tick in the expanse
        void doTick();

        // Receive input packet from a client
        void receiveInput(std::string input);
    private:
        //
        bool isPaused;

        // Send a message to the a client
        void sendMessage(std::string message);

        // Pulse rate, time to wait in between ticks
        unsigned int pulseRate;

        // How old the expanse is, in ticks
        long long expanseAge;

};

#endif // LIBIRID_SERVER_H
