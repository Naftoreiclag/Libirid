/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef LIBIRID_SERVER_H
#define LIBIRID_SERVER_H

#include <string>

#include "Libirid_Game.h"

class Libirid_Server
{
    public:
        Libirid_Server();
        ~Libirid_Server();

        // Does everything
        void run();

        // Pauses the game
        void pause();

        // Resumes the game
        void unpause();

        // Executes a single game tick
        void doTick();

        // Receive input packet from a client
        void receiveInput(std::string input);
    private:
        // The game to simulate
        Libirid_Game* game;

        // If we are to execute ticks or not
        bool isPaused;

        // Send a message to the a client
        void sendMessage(std::string message);

        // Pulse rate, time to wait in between ticks
        unsigned int pulseRate;

};

#endif // LIBIRID_SERVER_H
