/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef ENTITY_H
#define ENTITY_H

#include "Node.h"

namespace node
{
    class NodeEntity : public Node
    {
        public:
            NodeEntity(std::string name, Node* parent);
            virtual ~NodeEntity();
        private:
    };
}

#endif // ENTITY_H
