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

        // Take over thread and do stuff
        void run();

        // Pauses the game
        void pause();

        // Resumes the game
        void unpause();

        // Receive input packet from a client
        void receiveInput(std::string input);
    // Maybe make these static someday? Maybe in Node_Expanse?
    private:
        node::Node_Expanse* loadExpanse(std::string saveFileName);
    private:
        // The game to simulate
        Libirid_Game* game;

        // Load game stuff
        void load();

        // Save game stuff
        void save();

        // Executes a single game tick
        void doTick();

        // If we are to execute ticks or not
        bool isPaused;

        // Send a message to the a client
        void sendMessage(std::string message);

        // Pulse rate, time to wait in between ticks
        unsigned int pulseRate;

};

#endif // LIBIRID_SERVER_H
