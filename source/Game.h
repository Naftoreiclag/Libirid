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
#include <vector>

namespace node
{
    class Node;
}
namespace cmd
{
    class CmdDictionary;
}

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
        node::Node* nodeExpanse;
        node::Node* nodeSpawnAreaChild;

        //
        node::Node* nodePlayerScript;

        // Command dictionary
        cmd::CmdDictionary* cmdDict;
    public:
        // Save to disk
        void save();

        // Load from disk
        void load();
    private:
        //
        void addPlayer(std::string playerName);

    ///////////////
    // Utilities //
    ///////////////

    public:
        // Pauses program and gets the stuff typed in and puts each word into wordList in lowercase
        static void getWordsLowercase(std::vector<std::string>* wordList);
};

#endif // GAME_H
