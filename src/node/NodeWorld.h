/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef WORLD_H
#define WORLD_H

#include "Node.h"

namespace node
{
    class NodeWorld : public Node
    {
        public:
            NodeWorld(std::string name, Node* parent);
            virtual ~NodeWorld();
        private:
    };
}

#endif // WORLD_H
