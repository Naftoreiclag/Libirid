/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef TICKABLENODE_H
#define TICKABLENODE_H

#include "Node.h"

namespace node
{
    class TickableNode: public Node
    {
        protected:
            // Nodes themselves are not instantainable, so you need to make a subclass of this.
            TickableNode(std::string name, NodeType nodeType, Node* parent);
        public:
            // Deleter. Also deletes all children, and their children's children and so on
            virtual ~TickableNode();
    };
}

#endif // TICKABLENODE_H
