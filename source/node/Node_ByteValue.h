/* Copyright (c) 2013-2014 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_BYTEVALUE_H
#define NODE_BYTEVALUE_H

#include "Node.h"

namespace node
{
    class Node_ByteValue : public Node
    {
        public:
            Node_ByteValue(std::string name, Node* parent, int value);
            virtual ~Node_ByteValue();

            int value;
    };
}

#endif // NODE_BYTEVALUE_H
