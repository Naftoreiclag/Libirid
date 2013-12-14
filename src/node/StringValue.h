/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef STRINGVALUE_H
#define STRINGVALUE_H

#include "Node.h"

namespace node
{
    class StringValue : public Node
    {
        public:
            StringValue(std::string name, Node* parent, std::string value);
            virtual ~StringValue();

            std::string value;
    };
}

#endif // STRINGVALUE_H
