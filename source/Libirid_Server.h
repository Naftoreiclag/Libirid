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
        Libirid_Server(unsigned int pulseRate, std::string expanseSave, std::string conceptsSave);
        ~Libirid_Server();

        // Take over thread and do stuff
        void run();

        // Pauses the game
        void pause();

        // Resumes the game
        void unpause();

    // Maybe make these static someday? Maybe in Node_Expanse?
    private:
        node::Node_Expanse* loadExpanse(std::string saveFileName);

    private:
        // The game to simulate
        Libirid_Game* game;

        // Executes a single game tick
        void doTick();

        // If we are to execute ticks or not
        bool isPaused;

        // Save file paths
        std::string expanseSave;
        std::string conceptsSave;

        // How fast should the ticks be in ms
        unsigned int pulseRate;

};

#endif // LIBIRID_SERVER_H
