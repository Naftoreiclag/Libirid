/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "expanse/Node.h"

class Game
{
    public:
        bool runCommandFromRawInput(std::vector<std::string>* inputWords);
        bool runCommandFromSudoInput(std::string sudoLine);
        void run();

        //
        void addPlayer(std::string playerName);

        // Save to file
        void save();

        // Load
        void load();
        Game();
    private:
        // Is it running?
        bool running;

        // Nodes of interest
        Node* nodeExpanse;
        Node* nodeSpawnAreaChild;
};

#endif // GAME_H
