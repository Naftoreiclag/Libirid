/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_WORLD_H
#define NODE_WORLD_H

#include "Node.h"

namespace node
{
    class Node_World : public Node
    {
        public:
            Node_World(std::string name, Node* parent);
            virtual ~Node_World();
        private:
    };
}

#endif // NODE_WORLD_H
