/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_16VALUE_H
#define NODE_16VALUE_H

#include "Node.h"

namespace node
{
    class Node_16Value : public Node
    {
        public:
            Node_16Value(std::string name, Node* parent, int value);
            virtual ~Node_16Value();

            int value;
    };
}

#endif // NODE_16VALUE_H
