/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_INTEGERVALUE_H
#define NODE_INTEGERVALUE_H

#include "Node.h"

namespace node
{
    class Node_IntegerValue : public Node
    {
        public:
            Node_IntegerValue(std::string name, Node* parent, int value);
            virtual ~Node_IntegerValue();

            int value;
    };
}

#endif // NODE_INTEGERVALUE_H
