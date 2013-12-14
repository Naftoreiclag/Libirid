/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_ENTITY_H
#define NODE_ENTITY_H

#include "Node.h"

namespace node
{
    class Node_Entity : public Node
    {
        public:
            Node_Entity(std::string name, Node* parent);
            virtual ~Node_Entity();
        private:
    };
}

#endif // NODE_ENTITY_H
