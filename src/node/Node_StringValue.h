/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef NODE_STRINGVALUE_H
#define NODE_STRINGVALUE_H

#include "Node.h"

namespace node
{
    class Node_StringValue : public Node
    {
        public:
            Node_StringValue(std::string name, Node* parent, std::string value);
            virtual ~Node_StringValue();

            std::string value;
    };
}

#endif // NODE_STRINGVALUE_H
