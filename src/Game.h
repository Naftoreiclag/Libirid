/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <map>

#include "expanse/Expanse.h"
#include "expanse/World.h"
#include "expanse/Area.h"
#include "expanse/Entity.h"
#include "expanse/Portal.h"

class Game
{
    public:
        //World* world;
        //Player* player;
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
        bool running;

        std::vector<Node*> nodes;

        // ??
        exp::Expanse* expanse;

        //
        Node* spawnAreaChild;
};

#endif // GAME_H
