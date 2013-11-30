/* Copyright (c) 2013 "Naftoreiclag" https://github.com/Naftoreiclag
 *
 * Distributed under the MIT License (http://opensource.org/licenses/mit-license.html)
 * See accompanying file LICENSE
 */

#ifndef INTEGERVALUE_H
#define INTEGERVALUE_H

#include "Node.h"

namespace exp
{
    class IntegerValue : public Node
    {
        public:
            IntegerValue(std::string name, Node* parent, int value);
            virtual ~IntegerValue();

            int value;
    };
}

#endif // INTEGERVALUE_H
