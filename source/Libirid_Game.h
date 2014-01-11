/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef LIBIRID_GAME_H
#define LIBIRID_GAME_H

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

class Libirid_Game
{
    public:
        // Initialize
        Libirid_Game();

        // Finalize
        virtual ~Libirid_Game();
    private:
        // Nodes of interest
        node::Node* nodeExpanse;
        node::Node* nodeConcepts;
        node::Node* nodeSpawnAreaChild;
        node::Node* nodePlayerScript;

        // Run a player command
        void runPlayerCommand(node::Node* nodePlayerScript, std::string theirInput);
    public:
        // Do a tick
        void doTick();
    public:
        // Save to file
        void save(std::string fileName);

        // Load from file
        void load(std::string fileName);
    private:
        // Add a player
        void addPlayer(std::string playerName);

        // How old the expanse is, in ticks
        long long expanseAge;

    ///////////////
    // Utilities //
    ///////////////

    public:
        // Split a line into words
        static void splitWordsLowercase(std::string line, std::vector<std::string>* wordList);
};

#endif // LIBIRID_GAME_H
