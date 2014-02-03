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
    class TickableNode;
    class Node_Expanse;
    class Node_Folder;
    class Node_Script;
}
namespace cmd
{
    class CmdDictionary;
}

class Libirid_Game
{
    public:
        // Initialize
        Libirid_Game(node::Node_Expanse* nodeExpanse, node::Node_Folder* nodeConcepts);

        // Finalize
        virtual ~Libirid_Game();
    private:
        // Nodes of interest
        node::Node_Expanse* nodeExpanse;
        node::Node_Folder* nodeConcepts;

        //
        std::vector<node::TickableNode*> tickableNodes;
    public:
        // Do a tick
        void doTick();
    private:
        //
        void findTickableNodes();
    private:
        // Add a player
        void addPlayer(std::string playerName);
};

#endif // LIBIRID_GAME_H
