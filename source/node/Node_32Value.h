/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_32VALUE_H
#define NODE_32VALUE_H

#include "Node.h"

namespace node
{
    class Node_32Value : public Node
    {
        public:
            Node_32Value(std::string name, Node* parent, int value);
            virtual ~Node_32Value();

            int value;
    };
}

#endif // NODE_32VALUE_H
