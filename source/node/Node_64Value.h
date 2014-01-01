/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_64VALUE_H
#define NODE_64VALUE_H

#include "Node.h"

namespace node
{
    class Node_64Value : public Node
    {
        public:
            Node_64Value(std::string name, Node* parent, int value);
            virtual ~Node_64Value();

            int value;
    };
}

#endif // NODE_64VALUE_H
