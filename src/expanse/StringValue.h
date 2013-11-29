/* Copyright (c) 2013 https://github.com/Naftoreiclag/
 *
 * Distributed under the MIT License (referring to license referred to at http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef STRINGVALUE_H
#define STRINGVALUE_H

#include "Node.h"

namespace exp
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
