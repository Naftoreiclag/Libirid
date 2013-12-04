/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef GAME_H
#define GAME_H

/* Game instance. Load from file, play some games, save to file.
 *
 */

#include <string>

class Node;
class lua_State;

class Game
{
    public:
        // Initialize
        Game();

        // Finalize
        virtual ~Game();

        // Runs this game; hangs main program until game finishes
        void run();
    private:
        // Is it running?
        bool isRunning;

        // Nodes of interest
        Node* nodeExpanse;
        Node* nodeSpawnAreaChild;

        // Lua state
        lua_State* luaState;
    public:
        // Save to disk
        void save();

        // Load from disk
        void load();
    private:
        //
        void addPlayer(std::string playerName);
};

#endif // GAME_H
